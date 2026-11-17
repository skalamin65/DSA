class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    int m = len / d;       
                    int changes = 0;
                    for (int r = 0; r < d; r++) {
                        for (int a = 0, b = m - 1; a < b; a++, b--) {
                            if (s[i + r + a * d] != s[i + r + b * d]) changes++;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int j = 1; j <= k; j++) {
            for (int i = 2 * j; i <= n; i++) {
                for (int p = 2 * (j - 1); p <= i - 2; p++) {
                    if (dp[j - 1][p] == INF || cost[p][i - 1] == INF) continue;
                    dp[j][i] = min(dp[j][i], dp[j - 1][p] + cost[p][i - 1]);
                }
            }
        }
        return dp[k][n];
    }
};