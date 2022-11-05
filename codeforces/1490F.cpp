// nguoi gi dau ma` xinh dzu~ z

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int inf = 1e9 + 7;
const int maxN = 200010;

void solve()
{
    int n; cin >> n;

    vector<int> a(maxN);

    for (int i = 0; i < n; ++i)
    {
        int u; cin >> u;
        a[u]++;
    }

    sort(a.begin(), a.end());

    vector<int> p;
    p.push_back(0);

    for (int i = 0; i < maxN; ++i)
    {
        if (a[i]) p.push_back(a[i]);
    }

    for (int i = 1; i < p.size(); ++i)
    {
        p[i] = p[i] + p[i - 1];
    }

    int res = INT_MAX;
    for (int i = 0; i < p.size(); ++i)
    {
        res = min(res, p[i]);
    }

    cout << res << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}




