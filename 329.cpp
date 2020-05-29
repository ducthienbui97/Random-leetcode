// leetcode 329. Longest Increasing Path in a Matrix
class Solution {
public:
    vector<vector<int> > F;
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    int get(int x,int y, vector<vector<int>>& matrix){
        if(F[x][y])
            return F[x][y];
        F[x][y] = 1;
        for(int d = 0; d < 4; d++)
            if(x + X[d] >= 0 && x + X[d] < matrix.size() &&
              y + Y[d] >= 0 && y + Y[d] < matrix[x].size() &&
              matrix[x][y] < matrix[x + X[d]][y + Y[d]])
                F[x][y] = max(F[x][y], get(x + X[d],y + Y[d], matrix) + 1);
        return F[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;
        F = vector<vector<int> > (matrix.size(), vector<int> (matrix[0].size(), 0));
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0 ;j < matrix[i].size(); j++)
                ans = max(ans, get(i,j,matrix));
        return ans;
    }
};
