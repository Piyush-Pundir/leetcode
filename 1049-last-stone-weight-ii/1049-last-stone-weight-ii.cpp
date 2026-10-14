class Solution {
public:
    int lastStoneWeightII(vector<int>& arr) {
        int n = arr.size();
        int totSum = 0;
        for (int i=0; i<n; i++) totSum += arr[i];


        int target = totSum;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (arr[0] <= target)
            dp[0][arr[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = dp[ind - 1][t];

                bool take = false;
                if (arr[ind] <= t)
                    take = dp[ind - 1][t - arr[ind]];

                dp[ind][t] = take || notTake;
            }
        }

        // dp[n-1][col->0....totalSum]
        int mini = 1e9;
        for (int s1=0; s1<=totSum/2; s1++) {
            if (dp[n-1][s1]==true) {
                mini = min(mini, abs((totSum-s1)-s1));
            }
        }

        return mini;

    }
};