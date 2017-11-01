#include <vector>
using namespace std;
/**
 * Memory Complexity O(mn)
 */
// class Solution {
// public:
//     int findLength(vector<int>& A, vector<int>& B) {
//         vector<vector<int> > C(A.size() + 1, vector<int>(B.size() + 1, 0));
//         int result = 0;
//         for (int i = 1; i < A.size() + 1; ++i) {
//             for (int j = 1; j < B.size() + 1; ++j) {
//                 if (A[i - 1] == B[j - 1]) {
//                     C[i][j] = C[i - 1][j - 1] + 1;
//                 }
//                 result = result > C[i][j] ? result : C[i][j];
//             }
//         }
//         return result;
//     }
// };

/**
 * Memory Complexity O(n)
 */
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int> > C(2, vector<int>(B.size() + 1, 0));
        int result = 0;
        int first = 0;
        int second = 1;
        for (int i = 1; i < A.size() + 1; ++i) {
            for (int j = 1; j < B.size() + 1; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    C[second][j] = C[first][j - 1] + 1;
                } else {
                    C[second][j] = 0;
                }
                result = result > C[second][j] ? result : C[second][j];
            }
            swap(first, second);
        }
        return result;
    }
};