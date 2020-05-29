// Leetcode 146. LRU Cache
class LRUCache {
public:
    int capacity, cnt;
    struct Node{
        Node *l,*r;
        int key;
        int value;
    };
    Node *head,*tail;
    unordered_map<int,Node*> cache_map;
    LRUCache(int capacity): capacity(capacity) {
        head = new Node();
        tail = new Node();
        head -> r = tail;
        tail -> l = head;
        cnt = 0;
    }
    
    int get(int key) {
        auto it = cache_map.find(key);
        if(it == cache_map.end())
            return -1;
        Node* current = it ->second;
        current -> l -> r = current -> r;
        current -> r -> l = current -> l;
        
        current -> r = head -> r;
        current -> l = head;
        
        current -> l -> r = current;
        current -> r -> l = current;
        return current -> value;
    }
    
    void put(int key, int value) {
        auto it = cache_map.find(key);
        Node* current;
        if(it != cache_map.end()){
            current = it -> second;
            current -> value = value;
            current -> l -> r = current -> r;
            current -> r -> l = current -> l;
        }
        else{
            current = new Node();
            current -> key = key;
            current -> value = value;
            
            
            cnt ++;
            cache_map[key] = current;
        }
        current -> r = head -> r;
        current -> l = head;    
        
        current -> l -> r = current;
        current -> r -> l = current;
        if(cnt > capacity){
            current = tail -> l;
            current -> l -> r = current -> r;
            current -> r -> l = current -> l;
                
            cache_map.erase(current->key);
            delete current;
            cnt --;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
