class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            adj[u].push_back({v, price});
        }

        // {cost, node, stops}
        queue<tuple<int, int, int>> q;

        q.push({0, src, 0});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {

            auto [cost, node, stops] = q.front();
            q.pop();

            // Already used maximum allowed flights
            // Don't expand further unless this is destination.
            if (stops > k) continue;

            for (auto [neighbor, price] : adj[node]) {

                int newCost = cost + price;

                if (newCost < dist[neighbor]) {

                    dist[neighbor] = newCost;

                    q.push({
                        newCost,
                        neighbor,
                        stops + 1
                    });
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};