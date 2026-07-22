class Solution {
public:
vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

        if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        vector<vector<int>>edges;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int weights =abs(points[i][0] - points[j][0]) +
                             abs(points[i][1] - points[j][1]);

                edges.push_back({weights,i , j} );
            }
        }

        sort(edges.begin(), edges.end());
        int cost = 0;
        int edgeUsed = 0;

        for(auto &edge : edges){
            int weight = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(Union(u,v)){
                cost += weight;
                edgeUsed++;

                if(edgeUsed == n-1)
                break;
            }

            
        }
        return cost;
    }
};