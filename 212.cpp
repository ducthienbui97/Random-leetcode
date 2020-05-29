// Leetcode 212 Word Search II
class Solution {
public:
    struct Node{
        unordered_map<char,int> _next;
        int cnt;
        bool isStop;
        int pr;
        Node(int pr = -1):pr(pr){
            cnt = 0;
            isStop = false;
        }
        bool hasNext(const char& c){
            return _next.find(c) != _next.end();
        }
    };
    vector<Node> trie;
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    void test(vector<vector<char>>&board,int i,int j, int idx, vector<string> &ans, string&s, vector<vector<bool>>&visited){
        if(trie[idx].isStop){
            int current = idx;
            trie[idx].isStop = false;
            while(current != -1){
                trie[current].cnt --;
                current = trie[current].pr;
            }
            ans.push_back(s);
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || visited[i][j]) return;
        if(trie[idx].hasNext(board[i][j]) && trie[trie[idx]._next[board[i][j]]].cnt >= 0){
            visited[i][j] = true;
            s.push_back(board[i][j]);
            for(int d = 0; d < 4; d++){
                test(board,i + X[d], j + Y[d], trie[idx]._next[board[i][j]], ans, s, visited);
            }
            s.pop_back();
            visited[i][j] = false;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie.push_back(Node());
        for(auto&s:words){
            int current = 0;
            for(auto& c:s){
                if(!trie[current].hasNext(c)){
                    trie[current]._next[c] = trie.size();
                    trie.push_back(Node(current));
                }
                current = trie[current]._next[c];
                trie[current].cnt ++;
            }
            trie[current].isStop = true;
        }
        vector<string> ans;
        vector<vector<bool> > visited(board.size(),vector<bool>(board[0].size(),0));
        string s;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                test(board, i, j, 0, ans, s, visited);
        return ans;
    }
};
