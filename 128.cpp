// Leetcode 128. Longest Consecutive Sequence
class Solution {
public:
    unordered_map<int,int> root;
    unordered_map<int,int> cnt;
    int findRoot(int u){
        if(root[u] != u) root[u] = findRoot(root[u]);
        return root[u];
    }
    void join(int u,int v){
        u = findRoot(u);
        v = findRoot(v);
        root[u] = v;
    }
    int longestConsecutive(vector<int>& nums) {
        for(auto&i:nums){
            if(root.find(i) == root.end())
                root[i] = i;
            if(root.find(i - 1) != root.end())
                join(i,i-1);
            if(root.find(i+1) != root.end())
                join(i,i+1);
        }
        for(auto&i:nums)
            findRoot(i);
        for(auto&i:root){
            cnt[i.second] ++;
        }
        int ans = 0;
        for(auto&i:cnt)
            ans = max(ans,i.second);
        return ans;
    }
};
