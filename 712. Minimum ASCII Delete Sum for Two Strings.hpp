#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * C[i][j] -- minimum cost of make s1[0...i-1] s2[0...j-1] ascii sum equal
 */
// class Solution {
// public:
//     int minimumDeleteSum(string s1, string s2) {
//         vector<vector<int> > C(s1.length() + 1, vector<int>(s2.length() + 1, 0));
//         // initial
//         for (int i = 1; i < s2.length() + 1; ++i) {
//             C[0][i] = C[0][i - 1] + s2[i - 1];
//         }
//         for (int i = 1; i < s1.length() + 1; ++i) {
//             C[i][0] = C[i - 1][0] + s1[i - 1];
//         }
//         for (int i = 1; i < s1.length() + 1; ++i) {
//             for (int j = 1; j < s2.length() + 1; ++j) {
//                 if (s1[i - 1] == s2[j - 1]) {
//                     C[i][j] =  C[i - 1][j - 1];
//                 } else {
//                     // delete s1[i-1] or s2[j-1]
//                     C[i][j] = min(C[i - 1][j] + s1[i - 1], C[i][j - 1] + s2[j - 1]);
//                 }
//             }
//         }
//         return C[s1.length()][s2.length()];
//     }
// };

/**
 * space Optimized
 */

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<int> C(s2.length() + 1, 0);
        // temp_j : C[i-1][j]
        // temp_j_one : C[i - 1][j - 1] 
        int temp_j, temp_j_one;
        for (int i = 1; i < s2.length() + 1; ++i) {
            C[i] = C[i - 1] + s2[i - 1];
        }
        for (int i = 1; i < s1.length() + 1; ++i) {
            temp_j_one = C[0];
            C[0] += s1[i - 1];
            for (int j = 1; j < s2.length() + 1; ++j) {
                temp_j = C[j];
                if (s1[i - 1] == s2[j - 1]) {
                    C[j] = temp_j_one;
                } else {
                    C[j] = min(temp_j + s1[i - 1], C[j - 1] + s2[j - 1]);
                }
                temp_j_one = temp_j;
            }
        }
        return C[s2.length()];
    }
};
