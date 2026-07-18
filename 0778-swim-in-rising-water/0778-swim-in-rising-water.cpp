class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int time = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            // Skip outdated entries
            if(time > dist[i][j])
                continue;

            // Destination reached
            if(i == n - 1 && j == n - 1)
                return time;

            for(auto &d : dir) {

                int x = i + d[0];
                int y = j + d[1];

                if(x >= 0 && y >= 0 && x < n && y < n) {

                    int newTime = max(time, grid[x][y]);

                    if(newTime < dist[x][y]) {

                        dist[x][y] = newTime;
                        pq.push({newTime, {x, y}});
                    }
                }
            }
        }

        return -1;
    }
};