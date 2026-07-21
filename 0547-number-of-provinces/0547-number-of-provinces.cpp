class Solution {
public:
    vector<int>parent, rank;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        int provinces = n;
        for(int i = 0; i < n; i ++){
            for(int j = i+1; j < n; j++){
                if(isConnected[i][j] == 1){

                if(Union(i,j)){
                    provinces--;
                }
                }
            }
        }
        return provinces;
    }
};