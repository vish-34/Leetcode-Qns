class Solution {
public:
    void dfs(vector<vector<int>>&image, int i, int j, int oldColor, int newColor){
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size())
        return;

        if(image[i][j] != oldColor)
        return;

        image[i][j] = newColor;

        dfs(image, i-1, j, oldColor, newColor);
        dfs(image, i+1, j, oldColor, newColor);
        dfs(image, i, j-1, oldColor, newColor);
        dfs(image, i, j+1, oldColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        if(oldColor == color)
        return image;

        dfs(image, sr, sc, oldColor, color);
        return image;
    }

};