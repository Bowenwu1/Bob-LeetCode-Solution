#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<int> status;
    vector<vector<int>> graph;
    vector<int> inGrade;
    vector<int> outGrade;
    stack<int> loop, temp_loop;
    int N;
    int nodeHaveTwoParent;
    bool whetherHaveLoop;
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        N = edges.size();
        whetherHaveLoop = false;
        nodeHaveTwoParent = -1;
        inGrade = vector<int>(N + 1, 0);
        outGrade = vector<int>(N + 1, 0);
        graph = vector< vector<int> >(N + 1,vector<int>(N + 1, -1));
        status = vector<int>(N + 1, 0);
        for (int i = 0; i < edges.size(); ++i) {
            // store the graph and store the order of edges at the mean time.
            graph[edges[i][0]][edges[i][1]] = i;
            ++inGrade[edges[i][1]];
            ++outGrade[edges[i][0]];
            if (2 == inGrade[edges[i][1]]) {
                // find node have two parent
                nodeHaveTwoParent = edges[i][1];
            }
        }
        for (int i = 1; i <= N; ++i) {
            if (true == whetherHaveLoop) {
                break;
            } else if (0 == status[i]) {
                temp_loop = stack<int>();
                temp_loop.push(i);
                status[i] = 1;
                this->DFS(i);
                status[i] = 2;
            }
        }
        // case 1
        if (false == whetherHaveLoop) {
            cout << "case one";
            int order = -1;
            for (int i = 1; i <= N; ++i) {
                if (graph[i][nodeHaveTwoParent] > order) {
                    order = graph[i][nodeHaveTwoParent];
                }
            }
            return edges[order];
        } else {
            int latestOccur = -1;
            while (!loop.empty()) {
                int child = loop.top();
                loop.pop();
                if (loop.empty()) {
                    break;
                }
                int parent = loop.top();
                cout << "path : " << parent << " " << child << endl;
                // case 2
                if (nodeHaveTwoParent != -1 && child == nodeHaveTwoParent) {
                    cout << "case 2" << endl;
                    return edges[graph[parent][child]];
                }
                if (graph[parent][child] > latestOccur) {
                    latestOccur = graph[parent][child];
                    cout << "case 3 : " << latestOccur << endl;                    
                }
            }
            return edges[latestOccur];
        }
    }

    void DFS(int start) {
        cout << "DFS : " << start << endl;
        for (int i = 1; i <= N; ++i) {
            if (graph[start][i] != -1) {
                // find loop
                if (1 == status[i]) {
                    temp_loop.push(i);
                    whetherHaveLoop = true;
                    loop = temp_loop;
                    return;
                } else if (0 == status[i]) {
                    temp_loop.push(i);
                    status[i] = 1;
                    this->DFS(i);
                    status[i] = 2;
                    temp_loop.pop();
                }
            }
        }
    }
};