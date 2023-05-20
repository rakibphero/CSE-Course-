#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj_list;

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n = 6;  // number of nodes
    visited.resize(n + 1, false);
    adj_list.resize(n + 1);

    // adding edges to the graph
    adj_list[1].push_back(2);
    adj_list[1].push_back(3);
    adj_list[2].push_back(4);
    adj_list[2].push_back(5);
    adj_list[3].push_back(5);
    adj_list[4].push_back(6);
    adj_list[5].push_back(6);

    int start_node = 1;  // starting node for DFS
    dfs(start_node);

    return 0;
}
