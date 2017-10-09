#include "685. Redundant Connection II.hpp"
#include <iostream>

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges = vector<vector<int>>(n, vector<int>(2, 0)); 
    for (int i = 0; i < n; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }
    auto result = Solution().findRedundantDirectedConnection(edges);
    cout << "result : " << endl
        << result[0] << " " << result[1];
}
