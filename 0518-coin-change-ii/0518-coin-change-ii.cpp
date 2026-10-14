class Solution {
private:
    long f(int ind, int T, vector<int>& coins, vector<vector<long>>& dp) {
        if(ind == 0) {
            return (T % coins[0] == 0);
        }

        if(dp[ind][T] != -1) return dp[ind][T];

        long notTake = f(ind - 1, T, coins, dp);
        long take = 0;

        if(coins[ind] <= T) take = f(ind, T - coins[ind], coins, dp);

        return dp[ind][T] = take + notTake;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(amount + 1, -1));

        return f(n - 1, amount, coins, dp);
    }
};