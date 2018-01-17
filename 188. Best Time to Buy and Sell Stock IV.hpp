/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // for weird input
        if (prices.size() <= 1) {
            return 0;
        }
        int n = prices.size();
        if (k >= n / 2) {
            // we have enough transactions times to earn all money
            int profit = 0;
            int temp;
            for (int i = 0; i < n - 1; ++i) {
                temp = prices[i + 1] - prices[i];
                if (temp > 0) {
                    profit += temp;
                }
            }
            return profit;
        }
        vector< vector<int> > maxProfitByKTransactionsBeforeDayI(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; ++i) {
            int localMax = maxProfitByKTransactionsBeforeDayI[i - 1][0] - prices[0];
            for (int j = 1; j < n; ++j) {
                maxProfitByKTransactionsBeforeDayI[i][j] = max(maxProfitByKTransactionsBeforeDayI[i][j - 1], localMax + prices[j]);
                localMax = max(localMax, maxProfitByKTransactionsBeforeDayI[i - 1][j] - prices[j]);
            }
        }
        return maxProfitByKTransactionsBeforeDayI[k][n - 1];
    }
};