class Solution {
public:

    int check(int x, int y, int m, int n, vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0)
            return 0;

        grid[x][y] = 0; 
        int count = 1;

        count += check(x+1, y, m, n, grid);     
        count += check(x-1, y, m, n, grid);     
        count += check(x, y+1, m, n, grid);     
        count += check(x, y-1, m, n, grid);       

        return count;
    }

    int maxArea(int m, int n, vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = check(i, j, m, n, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;  // edge case

        int m = grid.size();
        int n = grid[0].size();

        return maxArea(m, n, grid);
    }
};
