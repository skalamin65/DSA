class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
         k = min(k, n);
        vector<vector<pair<int,int>>> g(n);
        for (auto& e : edges) g[e[0]].push_back({e[1], e[2]});

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        using T = tuple<long long, int, int>; 
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cur] = pq.top();
            pq.pop();
            if (d > dist[u][cur]) continue;
            if (u == n - 1) return (int)d;

            for (auto& [v, w] : g[u]) {
                int nxt = (labels[u] == labels[v]) ? cur + 1 : 1;
                if (nxt > k) continue;
                long long nd = d + w;
                if (nd < dist[v][nxt]) {
                    dist[v][nxt] = nd;
                    pq.push({nd, v, nxt});
                }
            }
        }
        return -1;
    }
};