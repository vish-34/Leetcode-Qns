class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;
        int fresh = 0;
        int minutes = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        // Put all rotten oranges in the queue
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 2)
                    q.push({i, j});

                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty() && fresh > 0) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                auto curr = q.front();
                q.pop();

                for(auto &d : dir) {

                    int x = curr.first + d[0];
                    int y = curr.second + d[1];

                    if(x >= 0 && y >= 0 &&
                       x < rows && y < cols &&
                       grid[x][y] == 1) {

                        grid[x][y] = 2;
                        fresh--;

                        q.push({x, y});
                    }
                }
            }

            minutes++;
        }

        if(fresh > 0)
            return -1;

        return minutes;
    }
};