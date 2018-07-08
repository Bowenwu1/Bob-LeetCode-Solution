#include <vector>
#include <algorithm>
#include <iostream>
using std::cout;
using std::vector;
using std::min;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // first we use O(n^2) extra space to solve it
        vector<vector<int>> A = vector<vector<int>>(triangle.size(), vector<int>(triangle.size(), 0));
        A[0][0] = triangle[0][0];
        unsigned int size = triangle.size();
        for (unsigned int i = 1; i < size; ++i) {
            for (unsigned int j = 0; j <= i; ++j) {
                if (j != 0 && j != i) {
                    A[i][j] = min(A[i-1][j-1], A[i-1][j]) + triangle[i][j];
                } else if (j == 0) {
                    A[i][j] = A[i-1][j] + triangle[i][j];
                } else if (j == i) {
                    A[i][j] = A[i-1][j-1] + triangle[i][j];
                }
                // cout << i << " " << j << " " << A[i][j] << endl;
            }
        }
        // find minimum in the last layer
        int result = A[size-1][0];
        for (unsigned int i = 0; i < size; ++i) {
            result = min(result, A[size-1][i]);
        }
        return result;
    }
};