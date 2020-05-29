// Leetcode 3. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char,int> counter;
        int ans = 0;
        for(int l = -1,r = 0; r < s.size() ; r++){
            counter[s[r]] ++;
            while(counter[s[r]] > 1)
                counter[s[++l]] --;
            ans = std::max(ans,r - l);
        }
        return ans;
    }
};
