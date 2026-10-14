class Solution {
public:
    int lastStoneWeightII(vector<int>& arr) {
        int n = arr.size();
        int totSum = 0;
        for (int i=0; i<n; i++) totSum += arr[i];


        int target = totSum;
        vector<bool> prev(target + 1, 0), cur(target + 1, 0);

        prev[0] = true;

        if (arr[0] <= target)
            prev[arr[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            cur[0] = true;

            for (int t = 1; t <= target; t++) {
                bool notTake = prev[t];
                bool take = false;

                if (arr[ind] <= t)
                    take = prev[t - arr[ind]];

                cur[t] = take | notTake;
            }
            prev = cur;
        }

        // dp[n-1][col->0....totalSum]
        int mini = 1e9;
        for (int s1=0; s1<=totSum/2; s1++) {
            if (prev[s1]==true) {
                mini = min(mini, abs((totSum-s1)-s1));
            }
        }

        return mini;

    }
};




