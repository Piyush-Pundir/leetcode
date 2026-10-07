class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int cntCity = n;
        int cityNo = -1;

        for (int src = 0; src < n; src++) {

            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>,
                           vector<pair<int, int>>,
                           greater<pair<int, int>>> pq;

            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty()) {
                auto [dis, node] = pq.top();
                pq.pop();

                if (dis > dist[node])
                    continue;

                for (auto it : adj[node]) {
                    int adjNode = it.first;
                    int wt = it.second;

                    if (dis + wt < dist[adjNode]) {
                        dist[adjNode] = dis + wt;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }

            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (dist[i] <= distanceThreshold)
                    cnt++;
            }

            // <= because in case of tie, choose larger city number
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNo = src;
            }
        }

        return cityNo;
    }
};