class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<int,int>> q;

        // Put all 0's into the queue
        // Mark all 1's as unvisited (-1)
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(mat[i][j] == 0) {
                    q.push({i, j});
                }
                else {
                    mat[i][j] = -1;
                }
            }
        }

        int dir[4][2] = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            for(auto &d : dir) {

                int x = i + d[0];
                int y = j + d[1];

                if(x >= 0 && y >= 0 &&
                   x < rows && y < cols &&
                   mat[x][y] == -1) {

                    mat[x][y] = mat[i][j] + 1;

                    q.push({x, y});
                }
            }
        }

        return mat;
    }
};