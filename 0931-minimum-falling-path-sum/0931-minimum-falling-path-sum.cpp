class Solution {
private:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (j < 0 || j >= matrix[0].size()) return 1e8;

        if (i == 0) return matrix[0][j];

        if (dp[i][j] != INT_MAX) return dp[i][j];

        int u = matrix[i][j] + f(i - 1, j, matrix, dp);
        int ld = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
        int rd = matrix[i][j] + f(i - 1, j + 1, matrix, dp);

        return dp[i][j] = min(u, min(ld, rd));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        int maxi = INT_MAX;

        for (int j = 0; j < m; j++) {
            maxi = min(maxi, f(n - 1, j, matrix, dp));
        }

        return maxi;
    }
};