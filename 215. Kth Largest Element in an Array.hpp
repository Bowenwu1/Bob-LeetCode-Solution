/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/
#include <time.h>

class Solution {

public:
    int findKthLargest(vector<int>& nums, int k) {
        // get random number
        srand(time(NULL));
        int index = rand() % nums.size();
        int flag = nums[index];

        vector<int> smaller, equal, bigger;

        // group into three number
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < flag) {
                smaller.push_back(nums[i]);
            } else if (nums[i] == flag) {
                equal.push_back(nums[i]);
            } else {
                bigger.push_back(nums[i]);
            }
        }

        if (bigger.size() >= k) {
            return findKthLargest(bigger, k);
        } else if (bigger.size() + equal.size() < k) {
            return findKthLargest(smaller, k - bigger.size() - equal.size());
        } else {
            return flag;
        }
    }
};