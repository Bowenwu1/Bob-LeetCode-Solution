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