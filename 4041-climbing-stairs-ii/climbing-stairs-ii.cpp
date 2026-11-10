#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= 3 && j - k >= 0; ++k) {
                if (dp[j - k] == LLONG_MAX) continue;
                long long cand = dp[j - k] + costs[j - 1] + (long long)k * k;
                dp[j] = min(dp[j], cand);
            }
        }
        return (int)dp[n];
    }
};