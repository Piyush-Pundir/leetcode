class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n,-1));
        queue<pair<int, int>> q;
        int num=0;
        for (int row=0; row<m; row++) {
            for (int col=0; col<n; col++) {
                if (mat[row][col]==0) {
                    ans[row][col]=0;
                    q.push({row, col});
                } else {
                    num++;
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int cnt=0;
        while (!q.empty() && num>0) {
            cnt++;
            int size=q.size();
            for (int i=0; i<size; i++) {
                auto [row, col] = q.front();
                q.pop();
                for (int j=0; j<4; j++) {
                    int nrow = row+delrow[j];
                    int ncol = col+delcol[j];
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && ans[nrow][ncol]==-1) {
                        ans[nrow][ncol]=cnt;
                        num--;
                        q.push({nrow, ncol});
                    }
                }
            }

        }
        return ans;
    }
};