// Leetcode 436. Find Right Interval
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int> > index_left;
        for(int i = 0; i < intervals.size(); i++) {
            index_left.emplace_back(intervals[i][0], i);
        }
        sort(index_left.begin(), index_left.end());
        vector<int> ans;
        for(int i = 0; i < intervals.size(); i++) {
            auto found = lower_bound(index_left.begin(), index_left.end(), make_pair(intervals[i][1], 0));
            if(found == index_left.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(found -> second);
            }
        }
        return ans;
    }
};
