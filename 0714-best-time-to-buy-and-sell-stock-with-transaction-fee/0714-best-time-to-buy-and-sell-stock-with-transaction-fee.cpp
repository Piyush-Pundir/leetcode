class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int aheadNotBuy, aheadBuy, curNotBuy, curBuy;
        aheadNotBuy = aheadBuy = 0;

        for (int ind = n - 1; ind >= 0; ind--) {

            // buy
            curBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);

            // sell
            curNotBuy = max(prices[ind] - fee + aheadBuy, 0 + aheadNotBuy);

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }

        return aheadBuy;
    }
};