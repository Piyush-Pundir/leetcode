class Solution {
private:
    pair<bool, int> bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        bool escape = false;
        if (row == 0 || row == n-1 || col == 0 || col == m-1) {
            escape = true;
        }
        int land = 1;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
             // traverse in the neighbours and mark them if its a land
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (!escape) {
                    if (row == 0 || row == n-1 || col == 0 || col == m-1) {
                        escape = true;
                    }
                }

                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol]=1;
                    land++;
                    q.push({nrow, ncol});
                }
            }
        }
        return {escape, land};
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col<m; col++) {
                if (!vis[row][col] && grid[row][col]==1) {
                    pair<bool, int> p;
                    p = bfs(row, col, vis, grid);
                    if (!p.first) {
                        cnt += p.second;
                    }
                }
            }
        }
        return cnt;
    }
};