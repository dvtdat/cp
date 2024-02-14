/*
    Description: Min-cost max-flow. cap[i][j] != cap[j][i] is allowed; double
    edges are not. If costs can be negative, call setpi before maxflow, but note
    that negative cost cycles are not supported. To obtain the actual flow, look
    at positive values only
    Complexity: O(E^2)
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;

struct MCMF
{
    int N;
    vector<vector<int>> ed, red;
    vector<vector<ll>> cap, flow, cost;
    vector<int> seen;
    vector<ll> dist, pi;
    vector<pair<int, int>> par;
    MCMF(int N) : N(N), ed(N), red(N), cap(N, vector<ll>(N)), flow(cap), cost(cap), seen(N), dist(N), pi(N), par(N) {}
    void addEdge(int from, int to, ll cap, ll cost)
    {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
    }
    void path(int s)
    {
        seen = vector<int>(N, 0);
        dist = vector<ll>(N, infLL);
        dist[s] = 0;
        ll di;
        
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
        q.push({0, s});
        vector<bool> in_queue(N, false);

        auto relax = [&](int i, ll cap, ll cost, int dir) {
            ll val = di - pi[i] + cost;
            if (cap && val < dist[i]) {
                dist[i] = val;
                par[i] = {s, dir};
                if (!in_queue[i]) {
                    q.push({-dist[i], i});
                    in_queue[i] = true;
                }
            }
        };

        while (!q.empty())
        {
            s = q.top().second;
            q.pop();
            seen[s] = 1;
            di = dist[s] + pi[s];
            for (int i : ed[s])
                if (!seen[i]) relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
            for (int i : red[s])
                if (!seen[i]) relax(i, flow[i][s], -cost[i][s], 0);
        }
        for (int i = 0; i < N; ++i) pi[i] = min(pi[i] + dist[i], infLL);
    }
    pair<ll, ll> maxflow(int s, int t)
    {
        ll totflow = 0, totcost = 0;
        while (path(s), seen[t])
        {
            ll fl = infLL;
            for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
                fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
            totflow += fl;
            for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
                if (r) flow[p][x] += fl;
                else flow[x][p] -= fl;
        }
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) totcost += cost[i][j] * flow[i][j];
        return {totflow, totcost};
    }
    // If some costs can be negative, call this before maxflow:
    void setpi(int s)
    { // (otherwise, leave th is out)
        pi = vector<ll>(pi.size(), infLL);
        pi[s] = 0;
        int it = N, ch = 1;
        ll v;
        while (ch-- && it--)
            for (int i = 0; i < N; ++i) if (pi[i] != infLL)
                for (int to : ed[i]) if (cap[i][to])
                    if ((v = pi[i] + cost[i][to]) < pi[to])
                        pi[to] = v,
                        ch = 1;
        assert(it >= 0); // negative cost cycle
    }
};

int main()
{
    int N = 4; // Number of nodes in the graph

    MCMF myGraph(N);

    // Adding edges with capacities and costs
    myGraph.addEdge(0, 1, 2, 2); // Edge from node 0 to node 1 with capacity 2 and cost 2
    myGraph.addEdge(0, 3, 1, 1); // Edge from node 0 to node 3 with capacity 1 and cost 1
    myGraph.addEdge(1, 2, 2, 1); // Edge from node 1 to node 2 with capacity 2 and cost 1
    myGraph.addEdge(1, 3, 1, 2); // Edge from node 1 to node 3 with capacity 1 and cost 2j

    int source = 0; // Source node
    int sink = 3;   // Sink node

    // If there are negative costs in the graph, you can call setpi function before maxflow
    // myGraph.setpi(source);

    // Find the maximum flow and minimum cost
    pair<ll, ll> res = myGraph.maxflow(source, sink);

    cout << "Maximum flow: " << res.first << endl;
    cout << "Minimum cost: " << res.second << endl;

    return 0;
}