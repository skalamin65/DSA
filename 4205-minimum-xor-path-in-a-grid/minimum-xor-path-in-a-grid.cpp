class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<bitset<1024>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<1024> prev;
                if (i == 0 && j == 0) {
                    prev.set(0);                
                } else {
                    if (i > 0) prev |= dp[j];    
                    if (j > 0) prev |= dp[j - 1];
                }
                int g = grid[i][j];
                bitset<1024> cur;
                for (int x = 0; x < 1024; x++) {
                    if (prev[x]) cur.set(x ^ g);
                }
                dp[j] = cur;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x]) return x;
        }
        return -1; 
    }
};