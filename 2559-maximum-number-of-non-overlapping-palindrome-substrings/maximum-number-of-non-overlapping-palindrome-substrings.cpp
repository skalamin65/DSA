class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (n < k) return 0;
        
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i < 2 || isPal[i+1][j-1])) {
                    isPal[i][j] = true;
                }
            }
        }
        
        vector<int> dp(n + 1, 0);
        for (int t = 1; t <= n; ++t) {
            dp[t] = dp[t-1];
            for (int j = 0; j <= t - k; ++j) {
                if (isPal[j][t-1]) {
                    dp[t] = max(dp[t], dp[j] + 1);
                }
            }
        }
        
        return dp[n];
    }
};