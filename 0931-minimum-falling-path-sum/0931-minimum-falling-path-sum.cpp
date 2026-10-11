class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m);

        for (int j = 0; j < m; j++)
            prev[j] = matrix[0][j];

        for (int i = 1; i < n; i++) {
            vector<int> cur(m);
            for (int j = 0; j < m; j++) {
                int u = matrix[i][j] + prev[j];

                int ld = matrix[i][j];
                if (j - 1 >= 0)
                    ld += prev[j - 1];
                else
                    ld = INT_MAX;

                int rd = matrix[i][j];
                if (j + 1 < m)
                    rd += prev[j + 1];
                else
                    rd = INT_MAX;

                cur[j] = min(u, min(ld, rd));
            }

            prev = cur;
        }

        int mini = INT_MAX;
        for (int j = 0; j < m; j++)
            mini = min(mini, prev[j]);

        return mini;
    }
};