class Solution {
private:
    int f(int ind, int T, vector<int> &nums, vector<vector<int>> &dp) {
        if(ind == 0) {
            if(T % nums[0] == 0) return T / nums[0];
            return 1e9;
        }

        if(dp[ind][T] != -1) return dp[ind][T];

        int notTake = 0 + f(ind-1, T, nums, dp);
        int take = INT_MAX;

        if(nums[ind] <= T) {
            take = 1 + f(ind, T - nums[ind], nums, dp);
        }

        return dp[ind][T] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;

        return ans;
    }
};