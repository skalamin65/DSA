class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        vector<vector<int>> up(LOG + 1, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n, 0), tout(n, 0), base(n, 0);

        int timer = 1; // BIT is 1-indexed
        vector<int> idx(n, 0), st;
        st.push_back(0);
        up[0][0] = 0;
        tin[0] = timer++;
        base[0] = 1 << (s[0] - 'a');
        while (!st.empty()) {
            int u = st.back();
            if (idx[u] < (int)adj[u].size()) {
                int v = adj[u][idx[u]++];
                if (v == up[0][u] && u != 0) continue;
                if (u == 0 && v == 0) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                base[v] = base[u] ^ (1 << (s[v] - 'a'));
                tin[v] = timer++;
                st.push_back(v);
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }
        for (int j = 1; j <= LOG; j++)
            for (int v = 0; v < n; v++)
                up[j][v] = up[j - 1][up[j - 1][v]];

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int j = 0; j <= LOG; j++)
                if (diff >> j & 1) a = up[j][a];
            if (a == b) return a;
            for (int j = LOG; j >= 0; j--) {
                if (up[j][a] != up[j][b]) {
                    a = up[j][a];
                    b = up[j][b];
                }
            }
            return up[0][a];
        };

        vector<int> bit(n + 2, 0);
        auto add = [&](int i, int d) {
            for (; i <= n + 1; i += i & -i) bit[i] ^= d;
        };
        auto pref = [&](int i) {
            int r = 0;
            for (; i > 0; i -= i & -i) r ^= bit[i];
            return r;
        };
        auto getP = [&](int u) { return base[u] ^ pref(tin[u]); };

        vector<bool> ans;
        for (auto &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int d = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                if (d) {
                    add(tin[u], d);
                    add(tout[u] + 1, d);
                    s[u] = c;
                }
            } else {
                int u, v;
                ss >> u >> v;
                int l = lca(u, v);
                int mask = getP(u) ^ getP(v) ^ (1 << (s[l] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};