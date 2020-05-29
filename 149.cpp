/**
 * Leet code 149. Max Points on a Line
 */
class Solution {
public:
    static bool compare(const vector<int>& one,const vector<int>& other) {
        if(one[0] == other[0])
            return one[1] < other[1];
        return one[0] < other[0];
    }
    
    int maxPoints(vector<vector<int>>& points) {
        
        if(points.size() <= 2)
            return points.size();
        sort(points.begin(),points.end(),compare);
        int ans = 1;
        for(int i = 0; i < points.size();){
            int same = 1;
            while(i + same < points.size() && points[i + same][0] == points[i][0] && points[i + same][1] == points[i][1])
                same ++;
            map<pair<int,int>,int> count;
            for(int j = i + same; j < points.size(); j++){
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];
                int g = __gcd(x, abs(y));
                x /= g;
                y /= g;
                count[{x,y}] ++;
            }
            ans = max(ans,same);
            for(auto&u:count)
                ans = max(ans,u.second + same);
            i += same;
        }
        return ans;
    }
    
};
