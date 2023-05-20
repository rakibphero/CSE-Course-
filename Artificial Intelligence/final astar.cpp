#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1e9; // set infinite distance
typedef pair<int, int> pi;
typedef vector<vector<pi>> Graph;
int astar(int start, int goal, Graph& adj_list)
{
    int n = adj_list.size();
    vector<int> dist(n, INF); // initialize distances
    vector<bool> visited(n, false); // visited nodes
    priority_queue<pi, vector<pi>, greater<pi>> pq; // min-heap
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
        {
            continue;
        }
        visited[u] = true;
        if (u == goal)   // found goal node
        {
            return dist[goal];
        }
        for (pi neighbor : adj_list[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            int new_dist = dist[u] + weight;
            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                int heuristic = abs(v - goal); // compute heuristic value
                pq.push(make_pair(new_dist + heuristic, v));
            }
        }
    }
    return -1; // no path found
}
int main()
{
    int n = 6; // number of nodes
    Graph adj_list(n);
// adding edges to the graph
    adj_list[0].push_back(make_pair(1, 1));
    adj_list[0].push_back(make_pair(5, 10));
    adj_list[1].push_back(make_pair(2, 2));
    adj_list[1].push_back(make_pair(3, 1));
    adj_list[2].push_back(make_pair(4, 5));
    adj_list[3].push_back(make_pair(4, 3));
    adj_list[3].push_back(make_pair(5, 4));
    adj_list[4].push_back(make_pair(5, 2));
    int start_node = 0; // starting node
    int goal_node = 5; // goal node
    int shortest_distance = astar(start_node, goal_node, adj_list);
    cout << "Shortest distance from node " << start_node << " to node " << goal_node << " is " << shortest_distance
         << endl;
    return 0;
}
