class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        int maxBal = (m + n) / 2 + 1;
        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(maxBal + 1, false)));

        return dfs(grid, 0, 0, 0, m, n, maxBal, visited);
    }

private:
    bool dfs(vector<vector<char>>& grid, int i, int j, int bal, int m, int n,
             int maxBal, vector<vector<vector<bool>>>& visited) {
        bal += (grid[i][j] == '(') ? 1 : -1;

        int remaining = (m - 1 - i) + (n - 1 - j);
        if (bal < 0 || bal > remaining) return false;

        if (i == m - 1 && j == n - 1) return bal == 0;

        if (visited[i][j][bal]) return false;
        visited[i][j][bal] = true;

        if (i + 1 < m && dfs(grid, i + 1, j, bal, m, n, maxBal, visited))
            return true;
        if (j + 1 < n && dfs(grid, i, j + 1, bal, m, n, maxBal, visited))
            return true;

        return false;
    }
};