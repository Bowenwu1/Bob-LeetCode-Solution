/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
// @author 吴博文
#include <algorithm>
#include <iostream>
class Solution {
public:
    double getMedian(vector<int> & a) {
        if (a.size() % 2) {
            return a[a.size() / 2];
        } else {
            return double(a[a.size() / 2] + a[a.size() / 2 - 1]) / 2;
        }
    }
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() == 0) {
            return getMedian(B);
        } else if (B.size() == 0) {
            return getMedian(A);
        }
        int m = A.size();
        int n = B.size();
        if(m > n) {
            std::swap(A, B);
            std::swap(m, n);
        }
        int i, j;
        int down = 0;
        int up = m;
        int halfLength = (m + n) / 2;
        // binary search
        while (down <= up) {
            i = (down + up) / 2;
            j = halfLength - i;
            std::cout << i << " " << j << std::endl;
            if (0 == j) {
                if (B[j] >= A[i - 1]) {
                    break;
                } else {
                    up = i - 1;
                    continue;
                }
            } else if (0 == i) {
                if (A[i] >= B[j - 1]) {
                    break;
                } else {
                    down = i + 1;
                    continue;
                }
            }
            // end condition
            if (B[j] >= A[i - 1] && A[i] >= B[j - 1]) {
                break;
            } else if (A[i] < B[j - 1]) {
                down = i + 1;
            } else if (B[j] < A[i - 1]) {
                up = i - 1;
            }
        }
       int maxOfLeft, minOfRight;
       if (0 == i) {
           maxOfLeft = B[j - 1];
       } else if (0 == j) {
           maxOfLeft = A[i - 1];
       } else {
           maxOfLeft = std::max(A[i - 1], B[j - 1]);
       }

       if (m == i) {
           minOfRight = B[j];
       } else if (n == j) {
           minOfRight = A[i];
       } else {
           minOfRight = std::min(A[i], B[j]);
       }

       if ((m + n) % 2) {
           return minOfRight;
       } else {
           return (double)(maxOfLeft + minOfRight) / 2;
       }
    }
};