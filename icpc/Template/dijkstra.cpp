/*
    Description: Dijkstra's algorithm for finding the shortest paths in a given graph using Heap.
    Complexity: O(E * logV)
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int inf = 2e9 + 7;
const int maxN = 200010;

void dijkstra(const int s, const int n, const vector<vector<ii>> &adj, int *d) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 0; i <= n; ++i) d[i] = inf;

    d[s] = 0;
    pq.push(ii(0, s));

    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if (du != d[u]) continue;

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (d[v] > du + w) {
                d[v] = du + w;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int main()
{
    int n = 6;  // Number of nodes
    vector<vector<ii>> adj(n + 1);

    // adj[u].push_back(ii(v, w))

    adj[1].push_back(ii(2, 2)); 
    adj[1].push_back(ii(4, 4));
    adj[2].push_back(ii(1, 2));
    adj[2].push_back(ii(3, 3));
    adj[2].push_back(ii(5, 1));
    adj[3].push_back(ii(2, 3));
    adj[3].push_back(ii(6, 2));
    adj[4].push_back(ii(1, 4));
    adj[4].push_back(ii(5, 3));
    adj[5].push_back(ii(2, 1));
    adj[5].push_back(ii(4, 3));
    adj[5].push_back(ii(6, 1));
    adj[6].push_back(ii(3, 2));
    adj[6].push_back(ii(5, 1));

    int d[maxN]; // Array to store the shortest distances
    int source = 1; // Source node from which we want to find the shortest paths

    dijkstra(source, n, adj, d);

    cout << "Shortest distances from node " << source << " to all other nodes:\n";
    for (int i = 1; i <= n; ++i)
    {
        cout << "Node " << i << ": " << d[i] << endl;
    }

    return 0;
}