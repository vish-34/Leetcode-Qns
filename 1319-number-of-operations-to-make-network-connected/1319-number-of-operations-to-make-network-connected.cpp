class Solution {
public:
    vector<int> parent, rank;

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool Union(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py){
            return false;
        }

        if(rank[px] > rank[py]){
            parent[py] = px;
        }else if(rank[px] < rank[py]){
            parent[px] = py;
        }else{
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1){
            return -1;
        }

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        int components = n;

        for(auto &edge : connections){
            int u = edge[0];
            int v = edge[1];

            if(Union(u, v)){
                components--;
            }
        }

        return components - 1;
    }
};