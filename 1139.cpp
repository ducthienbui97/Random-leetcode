#include <bits/stdc++.h>
using namespace std;

// Leetcode 1139. Largest 1-Bordered Square O(n^2)

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        vector<vector<int>> maxTLCorner(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> maxBRCorner(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> horizontal(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> vertical(grid.size(), vector<int>(grid[0].size(), 0));
        bool hasOne = false;

        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    horizontal[i][j] = 0;
                    vertical[i][j] = 0;
                } else {
                    hasOne = true;
                    horizontal[i][j] = j ? horizontal[i][j - 1] + 1 : 1;
                    vertical[i][j] = i ? vertical[i -1][j] + 1 : 1;
                }
                maxBRCorner[i][j] = min(horizontal[i][j], vertical[i][j]);
            }
        }

        for (int i = grid.size() - 1; i >= 0; i--) {
            for(int j = grid[i].size() - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    horizontal[i][j] = 0;
                    vertical[i][j] = 0;
                } else {
                    horizontal[i][j] = j < grid[i].size() - 1 ? horizontal[i][j + 1] + 1 : 1;
                    vertical[i][j] = i < grid.size() - 1 ? vertical[i + 1][j] + 1 : 1;
                }
                maxTLCorner[i][j] = min(horizontal[i][j], vertical[i][j]);

            }
        }

        int ans = hasOne;
        vector<deque<pair<int,int>>> best(grid.size() + grid[0].size());
        vector<deque<pair<int,int>>> best2(grid.size() + grid[0].size());

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) if(grid[i][j]) {
                int diag = i - j + grid[i].size();
                while(!best[diag].empty() && best[diag].front().second < j) {
                    best[diag].pop_front();
                }
                if (!best[diag].empty() && best[diag].front().first > j - maxBRCorner[i][j]) {
                    ans = max(ans, j - best[diag].front().first + 1);
                }
                best[diag].push_back(make_pair(j, j + maxTLCorner[i][j] - 1));
            }
        }

        for (int i = grid.size() - 1; i >= 0; i--) {
            for(int j = grid[i].size() - 1; j >= 0; j--) if(grid[i][j]) {
                int diag = i - j + grid[i].size();
                while(!best2[diag].empty() && best2[diag].front().first > j) {
                    best2[diag].pop_front();
                }
                if (!best2[diag].empty() && best[diag].front().second <= j + maxTLCorner[i][j] - 1) {
                    ans = max(ans, best2[diag].front().second - j + 1);
                }
                best2[diag].push_back(make_pair(j + 1 - maxBRCorner[i][j], j));
            }
        }
        return ans*ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v(10, vector<int> (10, 0));
    cout << sol.largest1BorderedSquare(v) << endl;
}
