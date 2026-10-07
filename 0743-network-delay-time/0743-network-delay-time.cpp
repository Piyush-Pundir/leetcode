class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);
        
        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
        }
        
        // distance[i] = shortest time from k to i
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        
        // {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        
        pq.push({0, k});
        
        while (!pq.empty()) {
            
            auto [dist, node] = pq.top();
            pq.pop();
            
            for (auto &[neighbor, weight] : adj[node]) {
                
                if (dist + weight < distance[neighbor]) {
                    
                    distance[neighbor] = dist + weight;
                    
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }
        
        // Maximum shortest distance = time for everyone to receive signal
        int answer = 0;
        
        for (int i = 1; i <= n; i++) {
            
            if (distance[i] == INT_MAX)
                return -1;
            
            answer = max(answer, distance[i]);
        }
        
        return answer;
    }
};