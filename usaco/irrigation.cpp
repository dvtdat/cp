// cuoc song nay la cuoc choi a

#include <bits/stdc++.h>
#define N 3010
#define inf 2e9

using namespace std;

typedef pair<long long, long long> ii;
typedef pair<long long, ii> iii;

long long x[N], y[N];
long long par[N];
vector<iii> edge;
long long n, c;

long long anc(long long u)
{
    return par[u] < 0 ? u : par[u] = anc(par[u]);
}

void join(long long u, long long v)
{
    par[anc(u)] = anc(v);
}

int main()
{
    memset(par, -1, sizeof par);

    freopen("irrigation.in", "r", stdin);
    freopen("irrigation.out", "w", stdout);

    cin >> n >> c;
    for (long long i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }

    for (long long i = 0; i < n; ++i)
    {
        for (long long j = 0; j < i; ++j)
        {
            long long tmp = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (tmp >= c)
            {
                edge.push_back(iii(tmp, ii(i, j)));
            }
        }
    }

    sort(edge.begin(), edge.end());

    vector<iii>::iterator it;
    long long res = 0;

    for (it = edge.begin(); it != edge.end(); it++)
    {
        if (anc(it->second.first) != anc(it->second.second))
        {
            join(it->second.first, it->second.second);
            res += it->first;
        }
    }

    if (res != 0) cout << res; else cout << -1;
}
