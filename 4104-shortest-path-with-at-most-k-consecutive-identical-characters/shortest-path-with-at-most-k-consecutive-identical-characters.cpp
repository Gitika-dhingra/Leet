#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Build adjacency list: adj[u] = list of {v, w}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        // Min-heap priority queue storing {weight, u, count}
        priority_queue<tuple<long long, int, int>, 
                       vector<tuple<long long, int, int>>, 
                       greater<tuple<long long, int, int>>> pq;

        // min_weight[u][count] to store the minimum weight to reach node u with a given count
        // Since k <= 50, we can use a 2D vector or hash map. 
        // Given n <= 50,000, a full 2D vector (50000 x 51) might exceed memory limit if not careful,
        // so we can use a flattened vector or a visited structure, or standard visited tracking.
        vector<vector<long long>> min_weight(n, vector<long long>(k + 1, -1));

        // Start from node 0. 
        // Initial count for node 0 is 1.
        pq.push({0, 0, 1});
        min_weight[0][1] = 0;

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            // If we reached the target node n - 1, return the total weight
            if (u == n - 1) {
                return d;
            }

            // If a shorter path to this state has already been processed, skip
            if (d > min_weight[u][count]) {
                continue;
            }

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                int next_count = 1;
                if (labels[u] == labels[v]) {
                    next_count = count + 1;
                }

                if (next_count <= k) {
                    long long next_dist = d + w;
                    if (min_weight[v][next_count] == -1 || next_dist < min_weight[v][next_count]) {
                        min_weight[v][next_count] = next_dist;
                        pq.push({next_dist, v, next_count});
                    }
                }
            }
        }

        return -1;
    }
};