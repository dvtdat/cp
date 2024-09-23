#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

int main()
{
    int n; cin >> n;

    map<int, priority_queue<ii>> pq;
    vector<int> a(n + 1), f(n + 1, 1), par(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        par[i] = i;
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (pq[a[i] + 1].empty()) pq[a[i] + 1] = priority_queue<ii>();
        pq[a[i] + 1].push(ii(1, i));

        if (pq[a[i]].empty()) continue;
        
        int u = pq[a[i]].top().first;
        int v = pq[a[i]].top().second;

        if (f[i] < f[v] + 1)
        {
            f[i] = f[v] + 1;
            par[i] = v;
            pq[a[i] + 1].push(ii(f[i], i));
        }
    }

    int ptr = 0;
    int mx = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (mx < f[i])
        {
            mx = f[i];
            ptr = i;
        }
    }
    cout << mx << '\n';

    vector<int> res;
    while (ptr != par[ptr])
    {
        res.push_back(ptr);
        ptr = par[ptr];
    }
    res.push_back(ptr);
    reverse(res.begin(), res.end());

    for (int i : res) cout << i << ' ';
}