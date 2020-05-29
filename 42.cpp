// leetcode 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        
        if(height.size()){    
            vector<int> left(height.size());
            vector<int> right(height.size());

            left[0] = -1;
            right.back() = -1;
            for(int i = 1; i < left.size(); i++){
                left[i] = max(left[i-1], height[i-1]);
            }
            for(int i = right.size() -2; i >= 0; i--){
                right[i] = max(right[i + 1], height[i +1]);
            }
            for(int i = 0; i < height.size(); i++){
                ans += max(min(left[i],right[i]) - height[i], 0);
            }
        }
        return ans;
    }
};
