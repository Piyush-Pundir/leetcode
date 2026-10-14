class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> prev(amount + 1, 0), cur(amount + 1, 0);

        for(int T = 0; T <= amount; T++) {
            prev[T] = (T % coins[0] == 0);
        }

        for(int ind = 1; ind < n; ind++) {
            for(int T = 0; T <= amount; T++) {
                long long notTake = prev[T];
                long long take = 0;

                if(coins[ind] <= T) {
                    take = cur[T - coins[ind]];
                }

                cur[T] = min(1LL * INT_MAX, take + notTake);
            }

            prev = cur;
        }

        return (int)prev[amount];
    }
};