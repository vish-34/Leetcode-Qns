class Solution {
public:
    void dfs(vector<vector<int>>&heights, int i, int j, vector<vector<int>>&vis){
        vis[i][j] = 1;
        int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(auto &d : dir){
            int x = i + d[0];
            int y = j +d[1];

            if(x >= 0 && y >= 0 && x < heights.size() && y < heights[0].size() && !vis[x][y] &&
            heights[x][y] >= heights[i][j]){
                dfs(heights, x, y, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pac(m, vector<int>(n,0));
        vector<vector<int>> alt(m, vector<int>(n,0));

        for(int i = 0; i < m; i++)
        dfs(heights, i, 0, pac);

        for(int j = 0; j < n; j++)
        dfs(heights, 0, j, pac);

        for(int i = 0; i < m; i++)
        dfs(heights, i, n-1, alt);

        for(int j = 0; j < n; j++)
        dfs(heights, m-1, j, alt);

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac[i][j] && alt[i][j])
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};