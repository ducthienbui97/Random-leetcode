// leetcode 8. String to Integer (atoi)
class Solution {
public:
    long long convert(string& s,int start = 0){
        long long val = 0;
        for(int i = start; i < s.size() && val <= INT_MAX; i++){
            char c = s[i];
            if(c < '0' || c > '9')
                return val;
            val = val*10 + c - '0';
                
        }
        return val;
    }
    int myAtoi(string str) {
        if(str.empty()){
            return 0;
        }
        int idx = 0;
        while(str[idx] == ' ')
            idx++;
        long long ans = 0;
        if(str[idx] == '-')
            ans = - convert(str,idx + 1);
        else if(str[idx] == '+')
            ans =  convert(str,idx + 1);
        else
            ans = convert(str, idx);
        if(ans > 1ll*INT_MAX)
            return INT_MAX;
        else if(ans < 1ll*INT_MIN)
            return INT_MIN;
        return ans;
    }
};
