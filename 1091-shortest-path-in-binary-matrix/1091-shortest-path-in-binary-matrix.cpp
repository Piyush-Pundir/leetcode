class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); // here m = n
        pair<int, int> source = {0,0};
        pair<int, int> destination = {n-1, m-1};
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;

        // edge case 
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        if (n == 1) return 1;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        dist[0][0] = 1;
        q.push({1, {source.first, source.second}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for (int i=0; i<8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 0 && dis+1 < dist[newr][newc]) {
                    dist[newr][newc] = 1 + dis;
                    if (newr == destination.first && newc == destination.second) return dis+1;
                    q.push({1+dis, {newr, newc}});
                }
            }
        }
        return -1;
    }
};