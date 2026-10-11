class Solution {
private:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }

        if (dp[i][j] != INT_MIN) return dp[i][j];

        int d = triangle[i][j] + f(i + 1, j, triangle, dp);
        int dg = triangle[i][j] + f(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(d, dg);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        return f(0, 0, triangle, dp);
    }
};