// Leetcode 239. Sliding Window Maximum
class Solution {
public:
    deque<int> slide;
    void insert(vector<int>&nums, int idx){
        while(!slide.empty() && nums[slide.back()] < nums[idx])
            slide.pop_back();
        slide.push_back(idx);
    }
    void check(int k){
        while(!slide.empty() && slide.back() - slide.front() >= k)
            slide.pop_front();
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            insert(nums, i);
            check(k);
            if(i >= k - 1 && !slide.empty())
                ans.push_back(nums[slide.front()]);
        }
        return ans;
    }
};
