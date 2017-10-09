#include <vector>
using namespace std;
class Solution {
private:
    vector<int> set;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set = vector<int>(edges.size() + 1);
        int N = edges.size();
        for (int i = 1; i <= N; ++i) {
            set[i] = i;
        }
        for (int i = 0; i < N; ++i) {
            if (this->find(edges[i][0]) == this->find(edges[i][1])) {
                return edges[i];
            } else {
                this->u(edges[i][0], edges[i][1]);
            }
        }
    }
    int find(int x) {
        if (set[x] != x) {
            set[x] = find(set[x]);
        }
        return set[x];
    }
    void u(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);
        set[xParent] = yParent;
    }
};