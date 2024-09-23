#include <bits/stdc++.h>

using namespace std;

vector<int> adj[110];

int main() {
    int n, m;
    cin >> n >> m;
    
    int start;
    cin >> start;

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> d(110, 0);
    auto bfs = [&](int start) {
        queue<int> q;
        q.push(start);
        d[start] = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (d[v] == 0) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    };

    bfs(start);

    for (int i = 0; i < n; ++i) cout << d[i] << '\n';
}