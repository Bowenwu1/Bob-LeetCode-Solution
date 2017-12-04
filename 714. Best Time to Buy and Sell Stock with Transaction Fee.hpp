/*
Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
*/

#include <vector>
#include <algorithm>
using namespace std;
// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         // have one stock on hand
//         vector<int> A(prices.size(), 0);
//         // no stock on hand
//         vector<int> B(prices.size(), 0);
//         A[0] = A[0] - prices[0];
//         for (int i = 1; i < prices.size(); ++i) {
//             A[i] = max(A[i - 1], B[i - 1] - prices[i]);
//             B[i] = max(B[i - 1], A[i - 1] + prices[i] - fee);
//         }
//         return B[prices.size() - 1];
//     }
// };

// space optimized
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // have one stock on hand
        int A = 0 - prices[0];
        // no stock on hand
        int B = 0;
        int B_temp;
        int A_temp;
        for (int i = 1; i < prices.size(); ++i) {
            A_temp = A;
            B_temp = B;

            A = max(A_temp, B_temp - prices[i]);

            B = max(B_temp, A_temp + prices[i] - fee);
        }
        return B;
    }
};