#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef unsigned long long ull;
    static constexpr ull MOD = (1ULL << 61) - 1;

    static ull mulmod(ull a, ull b) {
        __uint128_t t = (__uint128_t)a * b;
        ull lo = (ull)(t & MOD), hi = (ull)(t >> 61);
        ull r = lo + hi;
        if (r >= MOD) r -= MOD;
        return r;
    }

    vector<ull> pre, pw;
    int n;

    ull getHash(int l, int len) {
        ull r = pre[l + len] + MOD - mulmod(pre[l], pw[len]);
        if (r >= MOD) r -= MOD;
        return r;
    }

    bool existsUnique(int len) {
        vector<ull> hs;
        hs.reserve(n - len + 1);
        for (int i = 0; i + len <= n; i++) hs.push_back(getHash(i, len));
        sort(hs.begin(), hs.end());
        int m = hs.size();
        for (int i = 0; i < m;) {
            int j = i;
            while (j < m && hs[j] == hs[i]) j++;
            if (j - i == 1) return true;
            i = j;
        }
        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        n = nums.size();
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        ull base = rng() % (MOD - 1000000) + 500000;

        pre.assign(n + 1, 0);
        pw.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = mulmod(pre[i], base) + (ull)nums[i];
            if (pre[i + 1] >= MOD) pre[i + 1] -= MOD;
            pw[i + 1] = mulmod(pw[i], base);
        }

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (existsUnique(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};