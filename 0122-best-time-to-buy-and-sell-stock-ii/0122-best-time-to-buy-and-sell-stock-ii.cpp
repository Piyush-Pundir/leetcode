class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int aheadNotBuy, aheadBuy, curNotBuy, curBuy;
        aheadNotBuy = aheadBuy = 0;

        for (int ind = n - 1; ind >= 0; ind--) {

            curBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);

            curNotBuy = max(prices[ind] + aheadBuy, 0 + aheadNotBuy);

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }

        return aheadBuy;
    }
};