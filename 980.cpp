// Leetcode 980. Unique Paths III
class Solution {
public:
    constexpr const static int xDir[4] = {0,0,1,-1};
    constexpr const static int yDir[4] = {1,-1,0,0};
    int visit(int x, int y, int finishX, int finishY, int rows, int cols, int visited, int mark) {
        int current = 1 << (x*cols) + y;
        if(current & visited || !(current & mark)) {
            return 0;
        }
        if(x == finishX && y == finishY) {
            return (visited | current) == mark;
        }
        int rep = 0;
        for(int i = 0; i < 4; i++) {
            int nX = x + xDir[i];
            int nY = y + yDir[i];
            if(nX < 0 || nX >= rows || nY < 0 || nY >= cols)
                continue;
            rep += visit(nX, nY, finishX, finishY, rows, cols, visited | current, mark);
        }
        return rep;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int x,y, finishX, finishY;
        int mark = (1 << (rows*cols)) - 1;
        for(int i = 0; i< rows;i ++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    x = i;
                    y = j;
                } else if(grid[i][j] == 2) {
                    finishX = i;
                    finishY = j;
                } else if(grid[i][j] < 0) {
                    mark -= (1<<(i*cols + j));
                }
            }
        }
        
        return visit(x,y, finishX, finishY, rows, cols, 0, mark);
    }
};
