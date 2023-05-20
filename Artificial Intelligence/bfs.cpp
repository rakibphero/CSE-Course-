#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void bfs(int start, vector<vector<int>> &adj_list) {
vector<bool> visited(adj_list.size(), false);
queue<int> q;
visited[start] = true;
q.push(start);
while (!q.empty()) {
int u = q.front();
q.pop();
cout << u << " ";
for (int v : adj_list[u]) {
if (!visited[v]) {
visited[v] = true;
q.push(v);
}
}
}
}
int main() {
int n = 6; // number of nodes
vector<vector<int>> adj_list(n + 1); // adjacency list
// adding edges to the graph
adj_list[1].push_back(2);
adj_list[1].push_back(3);
adj_list[2].push_back(4);
adj_list[2].push_back(5);
adj_list[3].push_back(5);
adj_list[4].push_back(6);
adj_list[5].push_back(6);
int start_node = 1; // starting node for BFS
bfs(start_node, adj_list);
return 0;
}
