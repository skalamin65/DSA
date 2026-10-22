class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int z = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) { z = i; break; }
        }

        bool inc = true, dec = true;
        for (int i = 0; i < n; i++) {
            int nxt = nums[(i + 1) % n];
            if (nxt != (nums[i] + 1) % n) inc = false;
            if (nxt != (nums[i] - 1 + n) % n) dec = false;
        }

        const int INF = 1e9;
        int ans = INF;

        if (inc) {
            ans = min(ans, min(z, n - z + 2));
        }
        if (dec) {
            ans = min(ans, min(n - z, z + 2));
        }

        return ans == INF ? -1 : ans;
    }
};