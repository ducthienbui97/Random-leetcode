// leetcode 140. Word Break II
class Solution {
public:
    struct Node{
        unordered_map<char,int> _next;
        bool isStop;
        Node(){
            isStop = false;
        }
    };
    vector<int> isOk;
    vector<Node> trie;
    vector<vector<int> > d;
    vector<unordered_set<int> > r;
    bool dfs(int idx,string&s){
        if(idx == s.size()){
            return true;
        }
        if(isOk[idx] > 0)
            return isOk[idx] == 2;
        bool ok = false;
        for(int jdx:d[idx]){
            if(dfs(jdx, s)){
                r[idx].insert(jdx);
                ok = true;
            }
        }
        isOk[idx] = 1 + ok;
        return ok;
    }
    void dfs(int idx,string current,string&s, vector<string>& ans){
        if(idx == s.size()){
            ans.push_back(current);
            return;
        }
        for(int jdx:r[idx]){
            dfs(jdx,current + (idx > 0?" ":"") + s.substr(idx,jdx-idx), s, ans);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        trie.push_back(Node());
        d.resize(s.size());
        r.resize(s.size());
        isOk.resize(s.size());
        for(auto&s:wordDict){
            int current = 0;
            for(auto&c:s){
                if(trie[current]._next.find(c) == trie[current]._next.end()){
                    trie[current]._next[c] = trie.size();
                    trie.push_back(Node());
                }
                current = trie[current]._next[c];
            }
            trie[current].isStop = true;
        }
        for(int i = 0; i < s.size(); i++){
            int current = 0;
            for(int j = i; j < s.size(); j++){
                if(trie[current]._next.find(s[j]) == trie[current]._next.end())
                    break;
                current = trie[current]._next[s[j]];
                if(trie[current].isStop)
                    d[i].push_back(j + 1);
            }
        }
        vector<string> ans;
        if(dfs(0, s))
            dfs(0, "", s, ans);
        return ans;
    }
};
