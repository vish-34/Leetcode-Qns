class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j) {

        // Out of bounds
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;

        // Water or already visited
        if(grid[i][j] == 0)
            return;

        // Mark visited
        grid[i][j] = 0;

        int dir[4][2] = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        for(auto &d : dir) {

            int x = i + d[0];
            int y = j + d[1];

            dfs(grid, x, y);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Left and Right Borders
        for(int i = 0; i < rows; i++) {

            if(grid[i][0] == 1)
                dfs(grid, i, 0);

            if(grid[i][cols - 1] == 1)
                dfs(grid, i, cols - 1);
        }

        // Top and Bottom Borders
        for(int j = 0; j < cols; j++) {

            if(grid[0][j] == 1)
                dfs(grid, 0, j);

            if(grid[rows - 1][j] == 1)
                dfs(grid, rows - 1, j);
        }

        int count = 0;

        // Count remaining land
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};