#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct node {
    int id;
    double heuristic;
};

struct comparator {
    bool operator()(node i, node j) {
        return i.heuristic > j.heuristic;
    }
};

double heuristic_map[10] = {3, 2, 4, 1, 3, 1, 5, 2, 3}; // heuristic value for each node

vector<int> best_first_search(int start, int end, vector<vector<int>> &adj_list) {
    vector<bool> visited(adj_list.size(), false);
    priority_queue<node, vector<node>, comparator> pq;
    map<int, int> parent_map;

    pq.push({start, heuristic_map[start]});
    visited[start] = true;

    while (!pq.empty()) {
        node curr_node = pq.top();
        pq.pop();

        if (curr_node.id == end) {
            vector<int> path;
            int current = end;

            while (current != start) {
                path.push_back(current);
                current = parent_map[current];
            }

            path.push_back(start);
            reverse(path.begin(), path.end());
            return path; // path found
        }

        for (int neighbor : adj_list[curr_node.id]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent_map[neighbor] = curr_node.id;
                pq.push({neighbor, heuristic_map[neighbor]});
            }
        }
    }

    return vector<int>(); // path not found
}

int main() {
    int n = 10; // number of nodes
    vector<vector<int>> adj_list(n + 1); // adjacency list

    // adding edges to the graph
    adj_list[1].push_back(2);
    adj_list[1].push_back(3);
    adj_list[2].push_back(4);
    adj_list[2].push_back(5);
    adj_list[3].push_back(6);
    adj_list[3].push_back(7);
    adj_list[6].push_back(8);
    adj_list[7].push_back(9);
    adj_list[7].push_back(10);

    int start_node = 1; // starting node for BFS
    int end_node = 10; // ending node for BFS

    vector<int> path = best_first_search(start_node, end_node, adj_list);

    if (path.size() > 0) {
        cout << "Path found: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "Path not found.\n";
    }

    return 0;
}

