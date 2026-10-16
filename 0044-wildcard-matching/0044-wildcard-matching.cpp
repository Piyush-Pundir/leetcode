class Solution {
private:
    int f(int i, int j, string &pattern, string &text,
          vector<vector<int>> &dp) {

        if (i == 0 && j == 0) return true;
        if (i == 0 && j > 0) return false;

        if (j == 0 && i > 0) {
            for (int ii = 1; ii <= i; ii++) {
                if (pattern[ii - 1] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
            return dp[i][j] = f(i - 1, j - 1, pattern, text, dp);
        }

        if (pattern[i - 1] == '*') {
            return dp[i][j] = f(i - 1, j, pattern, text, dp)
                            || f(i, j - 1, pattern, text, dp);
        }

        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return f(n, m, p, s, dp);
    }
};