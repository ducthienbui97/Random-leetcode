// leetcode 126. Word Ladder II
class Solution {
public:
    bool isdistance1(const string& a, const string& b) {
        int distance = 0;
        for(int i = 0; i < a.size(); i++) {
            distance += a[i] != b[i];
        }
        return distance == 1;
    }
    
    void generateAnswer(const vector<vector<int>>& visitable, int v, 
                        vector<vector<string>>& ans, vector<string>& current,
                       const vector<string>& wordList, const string& beginWord) {
        if(v == 0) {
            current.push_back(beginWord);
            ans.push_back(vector<string>(current.rbegin(), current.rend()));
            current.pop_back();
            return;
        }
        current.push_back(wordList[v - 1]);
        for(auto& u: visitable[v]) {
            generateAnswer(visitable, u, ans, current, wordList, beginWord);
        }
        current.pop_back();
        
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<int>> d(wordList.size() + 1);
        vector<vector<string>> ans;
        vector<int> distance(wordList.size() + 1, 0);
        vector<vector<int>> visitable(wordList.size() + 1);
        
        int s = 0, f = -1;
        for(int i = 0; i < wordList.size(); i++) {
            if(isdistance1(beginWord, wordList[i])) {
                d[0].push_back(i + 1);
            }
            if(wordList[i] == endWord) {
                f = i + 1;
            }
            for(int j = i + 1; j < wordList.size(); j++) {
                if(isdistance1(wordList[i], wordList[j])) {
                    d[i + 1].push_back(j + 1);
                    d[j + 1].push_back(i + 1);
                }
            }
        }
                             
                              
        if(f < 0) {
            return ans;
        }
        queue<int> q;
        q.push(0);
        distance[0] = 1;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v: d[u]) {
                if(!distance[v]) {
                    q.push(v);
                    distance[v] = distance[u] + 1;
                }
                if(distance[v] == distance[u] + 1) {
                    visitable[v].push_back(u);
                }
            }
        }
        vector<string> temp;
        generateAnswer(visitable, f, ans, temp, wordList, beginWord);
        
        return ans;
}
};
