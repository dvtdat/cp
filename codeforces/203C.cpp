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
    int n, k; cin >> n >> k;
    int x, y; cin >> x >> y;

    vector<ii> a(n);
    vector<int> res;

    for (int i = 0; i < n; ++i)
    {
        int u, v; cin >> u >> v;
        a[i] = ii(u * x + v * y, i);
    }

    sort(a.begin(), a.end());

    int i = 0;
    while (k - a[i].first >= 0 && i < n)
    {
        k -= a[i].first;
        res.push_back(a[i].second);
        i++;
    }

    cout << i << '\n';
    for (int i : res) cout << i + 1 << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}



