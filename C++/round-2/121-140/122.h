class Solution {
public:
    /* allow unlimited number of transactions */
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i = 0;

        /* find all U-shape, memorize lowest price before, try to sell at each top */
        while (i < prices.size()) {
            while (i + 1 < prices.size() && prices[i] >= prices[i + 1])
                ++i;
            int buy = prices[i];
            while (i + 1 < prices.size() && prices[i] <= prices[i + 1])
                ++i;
            int sell = prices[i];
            profit += sell - buy;
            ++i;
        }
        return profit;
    }
};