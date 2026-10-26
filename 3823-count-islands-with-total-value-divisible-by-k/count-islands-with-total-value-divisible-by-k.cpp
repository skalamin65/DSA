class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] <= 0) continue;

                long long sum = 0;
                queue<pair<int,int>> q;
                q.push({i, j});
                sum += grid[i][j];
                grid[i][j] = 0; 

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto& d : dirs) {
                        int nx = x + d[0], ny = y + d[1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
                            sum += grid[nx][ny];
                            grid[nx][ny] = 0;
                            q.push({nx, ny});
                        }
                    }
                }

                if (sum % k == 0) ans++;
            }
        }
        return ans;
    }
};