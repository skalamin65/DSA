class Solution {
public:
    // Sk Alamin Hossain
    int numberOfSets(int n, int k) {
         const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        vector<long long> prefix(k + 1, 0);

        for (int i = 0; i < n; i++) dp[i][0] = 1;

        for (int j = 0; j <= k; j++) prefix[j] = 0;
        prefix[0] = dp[0][0]; 

        fill(prefix.begin(), prefix.end(), 0);
        prefix[0] = dp[0][0]; 

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i - 1][j] + prefix[j - 1]) % MOD;
            }
            for (int j = 0; j <= k; j++) {
                prefix[j] = (prefix[j] + dp[i][j]) % MOD;
            }
        }

        return (int)dp[n - 1][k];
    }
};