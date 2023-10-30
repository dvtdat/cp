// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

const int INF = 1000000000;
 
struct Edge {
    int a, b, cap, flow;
};

struct MaxFlow {
    int n, s, t;
    vector<int> d, ptr, q;
    vector< Edge > e;
    vector< vector<int> > g;

    MaxFlow(int _n) : n(_n), d(_n), ptr(_n), q(_n), g(_n) {
        e.clear();
        for (int i = 0; i < n; i++) {
            g[i].clear();
            ptr[i] = 0;
        }
    }

    void addEdge(int a, int b, int cap) {
        Edge e1 = { a, b, cap, 0 };
        Edge e2 = { b, a, 0, 0 };
        g[a].push_back( (int) e.size() );
        e.push_back(e1);
        g[b].push_back( (int) e.size() );
        e.push_back(e2);
    }
    int getMaxFlow(int _s, int _t) {
        s = _s; t = _t;
        int flow = 0;
        for (;;) {
            if (!bfs()) break;
            std::fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, INF))
                flow += pushed;
        }
        return flow;
    }

private:
    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = s;
        std::fill(d.begin(), d.end(), -1);
        d[s] = 0;

        while (qh < qt && d[t] == -1) {
            int v = q[qh++];
            for (int i = 0; i < (int) g[v].size(); i++) {
                int id = g[v][i], to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    int dfs(int v, int flow) {
        if (!flow) return 0;
        if (v == t) return flow;
        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
                to = e[id].b;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
};


void solve()
{
	int ANSMAX = 0, ANSMIN = 0;

	int n, m; cin >> n >> m;
	vector<ii> a, am, ai;

	for (int i = 0; i < n; ++i)
	{
		int u, v; cin >> u >> v;
		a.push_back(ii(v, u));

		if (i < m) am.push_back(ii(u, v));
		else ai.push_back(ii(u, v));
	}
	
	sort(a.begin(), a.end());

	for (int i = 1; i <= 400; ++i)
	{
		for (ii &x : a)
		{
			if (x.second <= i && i <= x.first)
			{
				x = ii(-1, -1);
				ANSMAX++;
				break;
			}
		}
	}

	// s = 0
	// t = 1601
	// math = [1, 400]
	// info = [401, 800]
	// time1 = [801, 1200] (of math)
	// time2 = [1201, 1600] (of info)

	MaxFlow flow(1700);
	const int start = 0;
	const int end = 1601;
	const int offset[3] = {400, 800, 1200};

	for (int i = 1; i <= 400; ++i)
	{
		flow.addEdge(i + offset[1], i + offset[2], 1);
		flow.addEdge(start, i, 1);
		flow.addEdge(i + offset[0], end, 1);
	}

	for (int i = 0; i < am.size(); ++i)
	{
		ii x = am[i];
		for (int j = x.first; j <= x.second; ++j)
		{
			flow.addEdge(i + 1, j + offset[1], 1);
		}
	}

	for (int i = 0; i < ai.size(); ++i)
	{
		ii x = ai[i];
		for (int j = x.first; j <= x.second; ++j)
		{
			flow.addEdge(j + offset[2], i + 1 + offset[0], 1);
		}
	}

	ANSMIN = flow.getMaxFlow(start, end);

	cout << ANSMAX << '\n' << ANSMIN << '\n';
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("text");
    int test = 1; //cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//

