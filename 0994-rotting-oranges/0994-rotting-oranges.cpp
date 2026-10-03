class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        queue<pair<int, int>> q;
        // Adding all rooten oranges to queue
        for (int row=0; row<m; row++) {
            for (int col=0; col<n; col++) {
                if (grid[row][col]==2) {
                    q.push({row, col});
                }
            }
        }
        //Applying bfs traversal to all rooten oranges added to queue
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int j=0; j<4; j++) {
                    int nrow = row+delrow[j];
                    int ncol = col+delcol[j];
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol]==1) {
                        grid[nrow][ncol]=2;
                        q.push({nrow, ncol});
                    }
                }
            }
            if (!q.empty()) {
                time++;
            }
        }
        // Checking is all oranges becime rooten or not
        for (int row=0; row<m; row++) {
            for (int col=0; col<n; col++) {
                if (grid[row][col]==1) {
                    return -1;
                }
            }
        }
        return time;
    }
};