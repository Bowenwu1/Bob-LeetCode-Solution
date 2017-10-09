/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
private:
    int clock;
    vector<bool> visited;
    vector<int> pre;
    vector<int> post;
    vector< vector<int> > graph;
    vector<int> inGrade;
    vector<int> outGrade;
    int N;
    void explore(int v) {
        cout << "explore : " << v << endl;
        visited[v] = true;
        previsit(v);
        for (int i = 1; i <= N; ++i) {
            // for all edges from v
            if (1 == graph[v][i] && false == visited[i]) {
                // means this edge is in DFS tree
                graph[v][i] = 2;
                explore(i);
            }
        }
        postvisit(v);
    }
    void previsit(int v) {
        pre[v] = clock;
        ++clock;
    }
    void postvisit(int v) {
        post[v] = clock;
        ++clock;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // first transfer the graph into Adjancent Matrix
        // from 1 to N
        N = edges.size();
        inGrade = vector<int>(N + 1, 0);
        outGrade = vector<int>(N + 1, 0);
        graph = vector< vector<int> >(N + 1,vector<int>(N + 1, 0));
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]][edges[i][1]] = 1;
            ++inGrade[edges[i][1]];
            ++outGrade[edges[i][0]];
        }

        // variable for DFS
        visited = vector<bool>(N + 1, false);
        pre     = vector<int>(N + 1, 0);
        post    = vector<int>(N + 1, 0);
        clock = 1;

        for (int i = 1; i <= N; ++i) {
            if (false == visited[i]) {
                this->explore(i);                
            }
        }

        for (int i = N - 1; i >= 0; --i) {
            int u = edges[i][0];
            int v = edges[i][1];
            // cross edges
            if ((pre[v] < post[v] && post[v] < pre[u] && pre[u] < post[u]) || （inGrade[v] > 1)) {
                cout << "Find Cross Edges" << endl;
                if (1 == outGrade[u] && 0 == inGrade[u]) {
                    cout << "pass this Cross Edge" << endl;
                    continue;
                }
                if (2 == graph[u][v]) {
                    cout << "pass this Cross Edge" << endl;
                    continue;
                }
                // cout << "Find Cross Edges" << endl;
                return edges[i];
            // Back Edges
            } else if (pre[v] < pre[u] && pre[u] < post[u] && post[u] < post[v]) {
                cout << "Find Back Edges" << endl;
                return edges[i];
            // Forward Edges
            } else if (pre[u] < pre[v] && pre[v] < post[v] && post[v] < post[u]) {
                // Means this is not a tree edges
                // When DFS the graph, those tree edges are labled 2
                if (1 == graph[u][v]) {
                    cout << "Find Forward Edges" << endl;
                    return edges[i];
                }
            }
        }
    }
};