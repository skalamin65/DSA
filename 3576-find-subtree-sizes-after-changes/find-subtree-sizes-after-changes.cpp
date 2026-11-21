class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> np(n, -1), order, saved(n, -1);
        order.reserve(n);
        int last[26];
        fill(last, last + 26, -1);

        vector<pair<int,int>> st;
        st.push_back({0, 0});
        while (!st.empty()) {
            auto [x, state] = st.back();
            st.pop_back();
            int c = s[x] - 'a';
            if (state == 1) {
                last[c] = saved[x];  
                continue;
            }
            order.push_back(x);
            if (x != 0) np[x] = (last[c] != -1) ? last[c] : parent[x];
            saved[x] = last[c];
            last[c] = x;
            st.push_back({x, 1});
            for (int ch : children[x]) st.push_back({ch, 0});
        }

        vector<int> ans(n, 1);
        for (int i = n - 1; i >= 1; i--) {
            int x = order[i];
            ans[np[x]] += ans[x];
        }
        return ans;
    }
};