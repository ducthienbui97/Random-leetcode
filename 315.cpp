// Leetcode 315. Count of Smaller Numbers After Self
class Solution {
public:
    void merge_sort(vector<pair<int,int> >&vec, vector<int>&count){
        if(vec.size() <= 1)
            return;
        vector<pair<int,int> > left;
        vector<pair<int,int> > right;
        int mid = vec.size()/2;
        for(int i = 0; i < mid; i++)
            left.push_back(vec[i]);
        for(int i = mid; i < vec.size(); i++)
            right.push_back(vec[i]);
        vec.clear();
        merge_sort(left,count);
        merge_sort(right,count);
        while(left.size() > 0 || right.size() > 0){
            if(left.size() == 0){
                vec.push_back(right.back());
                right.pop_back();
            }else if(right.size() == 0){
                vec.push_back(left.back());
                left.pop_back();
            }else if(left.back() > right.back()){
                vec.push_back(left.back());
                count[left.back().second] += right.size();
                left.pop_back();
            }else{
                vec.push_back(right.back());
                right.pop_back();
            }
        }
        reverse(vec.begin(),vec.end());
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int> > pp;
        for(int i = 0; i< nums.size(); i++)
            pp.emplace_back(nums[i],i);
        vector<int> count(nums.size(),0);
        merge_sort(pp,count);
        return count;
    }
};
