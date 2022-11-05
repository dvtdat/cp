// troi nang' chang chang, ai o ben nang`

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

void solve()
{
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(maxN);

    for (ll &i : a) cin >> i;

    sort(a.rbegin(), a.rend());

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        b[u]++;
        b[v + 1]--;
    }

    for (int i = 1; i < maxN; ++i) b[i] += b[i - 1];

    sort(b.rbegin(), b.rend());

    ll sum = 0;
    int i = 0;

    while (b[i] != 0)
    {
        sum += 1LL * b[i] * a[i];
        i++;
    }

    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}


