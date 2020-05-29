// Leetcode 76. Minimum Window Substring
class Solution {
public:
    string minWindow(string s, string t) {
        int ans_l = 0, ans_r = 0, ans_len = 1<<30;
        unordered_map<char,int> t_cnt;
        unordered_map<char,int> cnt;
        unordered_set<char> fitted;
        for(auto&c:t) t_cnt[c] ++;
        for(int i = 0, j = 0; i < s.size(); i++){
            if(t_cnt.find(s[i]) != t_cnt.end()){
                cnt[s[i]]++;
                if(cnt[s[i]] >= t_cnt[s[i]])
                    fitted.insert(s[i]);
            }
            while(j < i){
                if(t_cnt.find(s[j]) != t_cnt.end()){
                    if(cnt[s[j]] > t_cnt[s[j]])
                       cnt[s[j++]]--;
                    else
                        break;
                }
                else j++;
            }
            if(fitted.size() == t_cnt.size() && ans_len > i - j + 1){
                ans_l = j;
                ans_r = i + 1;
                ans_len = i - j + 1;
            }
        }
        return s.substr(ans_l,ans_r - ans_l);
    }
};
