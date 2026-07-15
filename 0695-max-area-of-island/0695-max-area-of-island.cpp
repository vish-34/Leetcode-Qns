class Solution {
public:
    int dfs(vector<vector<int>>&grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return 0;

        if(grid[i][j] == 0)
        return 0;

        grid[i][j] = 0;
        int area = 1;

        int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(auto &d : dir){
            int x = i + d[0];
            int y = j + d[1];
            area += dfs(grid, x, y);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea =0 ;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i, j);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;

    }
};