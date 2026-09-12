class Solution {
public:
    // Sk Alamin Hossain
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }

        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            next[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                auto skip = dp[i + 1][k];

                auto take = dp[next[i]][k - 1];

                take.first += a[i][2];

                take.second.push_back((int)a[i][3]);

                sort(take.second.begin(), take.second.end());

                if (take.first > skip.first ||
                    (take.first == skip.first &&
                     take.second < skip.second)) {
                    
                    dp[i][k] = take;
                }
                else {
                    dp[i][k] = skip;
                }
            }
        }

        return dp[0][4].second;
    }
};
