class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // for weird input
        if (prices.size() == 0) {
            return 0;
        }
        // min price to buy
        int minPrice = prices[0];
        // max profit to get
        int maxGain = 0;
        for (int i = 1; i < prices.size(); ++i) {
            maxGain = max(maxGain, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxGain;
    }
};