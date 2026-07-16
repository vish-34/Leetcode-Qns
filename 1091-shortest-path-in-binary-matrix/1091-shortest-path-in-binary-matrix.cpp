class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Start or end is blocked
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int,int>> q;

        q.push({0,0});

        // Distance of starting cell
        grid[0][0] = 1;

        int dir[8][2] = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},         {0,1},
            {1,-1},{1,0},{1,1}
        };

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            // Destination reached
            if(i == n-1 && j == n-1)
                return grid[i][j];

            for(auto &d : dir) {

                int x = i + d[0];
                int y = j + d[1];

                if(x >= 0 && y >= 0 &&
                   x < n && y < n &&
                   grid[x][y] == 0) {

                    grid[x][y] = grid[i][j] + 1;

                    q.push({x,y});
                }
            }
        }

        return -1;
    }
};