class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int currEffort = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            // Skip outdated entry
            if(currEffort > effort[i][j])
                continue;

            // Destination reached
            if(i == m-1 && j == n-1)
                return currEffort;

            for(auto &d : dir) {

                int x = i + d[0];
                int y = j + d[1];

                if(x >= 0 && y >= 0 && x < m && y < n) {

                    int newEffort = max(
                        currEffort,
                        abs(heights[x][y] - heights[i][j])
                    );

                    if(newEffort < effort[x][y]) {

                        effort[x][y] = newEffort;

                        pq.push({newEffort, {x, y}});
                    }
                }
            }
        }

        return 0;
    }
};