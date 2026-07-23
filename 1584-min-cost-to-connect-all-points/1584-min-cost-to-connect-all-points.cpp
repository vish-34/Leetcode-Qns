class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<bool> visited(n, false);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0,0});

        int cost = 0;
        int edgesUsed = 0;

        while(!pq.empty() && edgesUsed < n){

            auto [weight, u] = pq.top();
            pq.pop();

            if(visited[u])
                continue;

            visited[u] = true;
            cost += weight;
            edgesUsed++;

            for(int v = 0; v < n; v++){

                if(!visited[v]){

                    int newWeight =
                        abs(points[u][0] - points[v][0]) +
                        abs(points[u][1] - points[v][1]);

                    pq.push({newWeight, v});
                }
            }
        }

        return cost;
    }
};