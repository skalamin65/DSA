#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> f(m, vector<long long>(n, 0));
        f[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 || f[i][j] == 0) continue;

                for (int d = 0; d < 2; d++) {   
                    int x = i, y = j, dir = d;
                    while (true) {
                        int nx = x + (dir == 1);
                        int ny = y + (dir == 0);
                        if (nx >= m || ny >= n) break;      
                        if (grid[nx][ny] == 0) {            
                            f[nx][ny] = (f[nx][ny] + f[i][j]) % MOD;
                            break;
                        }
                        x = nx; y = ny;
                        dir ^= 1;
                    }
                }
            }
        }
        return f[m - 1][n - 1] % MOD;
    }
};