class SegmentTree {
    int n, k;
    vector<vector<int>> tree;

    void merge(const vector<int>& left, const vector<int>& right, vector<int>& res) {
        for (int i = 0; i <= k; ++i) {
            res[i] = 0;
        }
        res[k] = (left[k] * right[k]) % k;
        
        for (int i = 0; i < k; ++i) {
            res[i] += left[i];
            res[(left[k] * i) % k] += right[i];
        }
    }

    void build(int o, int l, int r, const vector<int>& nums) {
        if (l == r) {
            int val = nums[l] % k;
            tree[o][val] = 1;
            tree[o][k] = val; 
            return;
        }
        int m = l + (r - l) / 2;
        build(o * 2, l, m, nums);
        build(o * 2 + 1, m + 1, r, nums);
        merge(tree[o * 2], tree[o * 2 + 1], tree[o]);
    }

public:
    SegmentTree(const vector<int>& nums, int k) : n(nums.size()), k(k) {
        tree.assign(4 * n, vector<int>(k + 1, 0));
        build(1, 0, n - 1, nums);
    }

    void update(int o, int l, int r, int index, int value) {
        if (l == r) {
            for (int i = 0; i <= k; ++i) tree[o][i] = 0;
            int val = value % k;
            tree[o][val] = 1;
            tree[o][k] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (index <= m) {
            update(o * 2, l, m, index, value);
        } else {
            update(o * 2 + 1, m + 1, r, index, value);
        }
        merge(tree[o * 2], tree[o * 2 + 1], tree[o]);
    }

    vector<int> query(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return tree[o];
        }
        int m = l + (r - l) / 2;
        if (R <= m) {
            return query(o * 2, l, m, L, R);
        }
        if (L > m) {
            return query(o * 2 + 1, m + 1, r, L, R);
        }
        vector<int> left = query(o * 2, l, m, L, R);
        vector<int> right = query(o * 2 + 1, m + 1, r, L, R);
        vector<int> res(k + 1, 0);
        merge(left, right, res);
        return res;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree seg(nums, k);
        vector<int> ans;

        for (auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            
            seg.update(1, 0, n - 1, index, value);
            
            vector<int> pre = seg.query(1, 0, n - 1, start, n - 1);
            
            ans.push_back(pre[x]);
        }
        
        return ans;
    }
};