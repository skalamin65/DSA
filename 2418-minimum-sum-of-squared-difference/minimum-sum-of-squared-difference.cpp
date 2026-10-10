class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        int maxD = 0;
        vector<long long> cnt(100002, 0);
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            maxD = max(maxD, d);
        }

        for (int d = maxD; d >= 1 && k > 0; d--) {
            if (cnt[d] == 0) continue;
            long long moved = min(cnt[d], k);
            cnt[d] -= moved;
            cnt[d - 1] += moved;
            k -= moved;
        }

        long long ans = 0;
        for (int d = 1; d <= maxD; d++) {
            ans += cnt[d] * (long long)d * d;
        }
        return ans;
    }
};