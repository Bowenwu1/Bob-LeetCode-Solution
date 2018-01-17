/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // for weird input
        if (prices.size() <= 1) {
            return 0;
        }
        int n = prices.size();
        // min price before day i, item 0 is useless
        vector<int> minPricesBeforeDayI(n, 0);
        minPricesBeforeDayI[0] = prices[0];
        for (int i = 1; i < n; ++i) {
            minPricesBeforeDayI[i] = min(minPricesBeforeDayI[i - 1], prices[i - 1]);
        }
        // the profit gained by sell stock on day i
        vector<int> maxProfitSellOnDayI(n, 0);
        for (int i = 1; i < n; ++i) {
            // maxProfitSellOnDayI[i] = prices[i] - minPricesBeforeDayI[i];
            maxProfitSellOnDayI[i] = max(maxProfitSellOnDayI[i - 1], prices[i] - minPricesBeforeDayI[i]);
        }
        // maximum price after day i, item (n-1) is useless
        vector<int> maxPriceAfterDayI(n, 0);
        for (int i = n - 2; i > -1; --i) {
            maxPriceAfterDayI[i] = max(maxPriceAfterDayI[i + 1], prices[i + 1]);
        }
        // maximum profit can be gained by one transaction after day i, item (n-1) is useless
        vector<int> maxProfitBuyOnDayI(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            // maxProfitBuyOnDayI[i] = maxPriceAfterDayI[i] - prices[i];
            maxProfitBuyOnDayI[i] = max(maxProfitBuyOnDayI[i + 1], maxPriceAfterDayI[i] - prices[i]);
        }
        int resultTwoTransactions = 0;
        // too much time here
        // for (int i = 1; i < n - 1; ++i) {
        //     for (int j = i + 1; j < n - 1; ++j) {
        //         resultTwoTransactions = max(resultTwoTransactions, maxProfitSellOnDayI[i] + maxProfitBuyOnDayI[j]);
        //     }
        // }
        for (int i = 1; i < n; ++i) {
            resultTwoTransactions = max(resultTwoTransactions, maxProfitSellOnDayI[i] + maxProfitBuyOnDayI[i]);
        }
        int resultOneTransactions = 0;
        for (int i = 1; i < n; ++i) {
            resultOneTransactions = max(resultOneTransactions, maxProfitSellOnDayI[i]);
        }
        return max(resultOneTransactions, resultTwoTransactions);
    }
};