class Solution {
public:
    // Sk Alamin Hossain
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        
        // dp[i] = number of distinct subsequences (including empty) 
        // using first i characters
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        
        // last[c] = last index (1-indexed) where character c appeared
        vector<int> last(26, -1);
        
        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];
            dp[i] = (2 * dp[i - 1]) % MOD;
            
            if (last[c - 'a'] != -1) {
                // subtract subsequences counted twice 
                // (those already ending in c from previous occurrence)
                dp[i] = (dp[i] - dp[last[c - 'a'] - 1] + MOD) % MOD;
            }
            
            last[c - 'a'] = i;
        }
        
        // subtract 1 for the empty subsequence
        return (int)((dp[n] - 1 + MOD) % MOD);
    }
};