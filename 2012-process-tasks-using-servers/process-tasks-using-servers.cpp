class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> freeServers;

        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> busyServers;

        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans(m);
        long long time = 0;

        for (int j = 0; j < m; j++) {
            time = max(time, (long long)j);

            while (!busyServers.empty() && get<0>(busyServers.top()) <= time) {
                auto [t, w, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({w, idx});
            }

            if (freeServers.empty()) {
                time = get<0>(busyServers.top());
                while (!busyServers.empty() && get<0>(busyServers.top()) <= time) {
                    auto [t, w, idx] = busyServers.top();
                    busyServers.pop();
                    freeServers.push({w, idx});
                }
            }

            auto [w, idx] = freeServers.top();
            freeServers.pop();

            ans[j] = idx;
            busyServers.push({time + tasks[j], w, idx});
        }

        return ans;
    }
};