class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& image, int color,
             int pix) {
        image[i][j] = color;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int k = 0; k < 4; k++) {
            int newi = i + dir[k][0];
            int newj = j + dir[k][1];
            if ((newi >= 0 && newj >= 0 && newi < n && newj < m) &&
                image[newi][newj] == pix) {
                dfs(newi, newj, n, m, image, color, pix);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int n = image.size();
        int m = image[0].size();
        int pix = image[sr][sc];
        if (pix == color)
            return image;
        dfs(sr, sc, n, m, image, color, pix);
        return image;
    }
};