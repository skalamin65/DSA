class Solution {
    static const long long MOD = 1e9 + 7;
    vector<long long> sum, sq, lazy;

    void apply(int o, int len, long long k) {
        sq[o] += 2 * k * sum[o] + k * k * len;
        sum[o] += k * len;
        lazy[o] += k;
    }

    void push(int o, int l, int r) {
        if (lazy[o]) {
            int m = (l + r) / 2;
            apply(2 * o, m - l + 1, lazy[o]);
            apply(2 * o + 1, r - m, lazy[o]);
            lazy[o] = 0;
        }
    }

    void update(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(o, r - l + 1, 1);
            return;
        }
        push(o, l, r);
        int m = (l + r) / 2;
        if (ql <= m) update(2 * o, l, m, ql, qr);
        if (qr > m) update(2 * o + 1, m + 1, r, ql, qr);
        sum[o] = sum[2 * o] + sum[2 * o + 1];
        sq[o] = sq[2 * o] + sq[2 * o + 1];
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last;
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int p = -1;
            auto it = last.find(nums[r]);
            if (it != last.end()) p = it->second;
            update(1, 0, n - 1, p + 1, r);
            last[nums[r]] = r;
            ans = (ans + sq[1]) % MOD;
        }
        return (int)ans;
    }
};