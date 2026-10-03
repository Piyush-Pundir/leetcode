class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {

        visited[node] = 1;  // currently in DFS path

        for (int neighbor : adj[node]) {

            if (visited[neighbor] == 0) {
                if (dfs(neighbor, adj, visited))
                    return true;
            }
            else if (visited[neighbor] == 1) {
                // Found a node already in current DFS path
                return true;
            }
        }

        visited[node] = 2;  // completely processed
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // bi -> ai
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(i, adj, visited))
                    return false;
            }
        }

        return true;
    }
};