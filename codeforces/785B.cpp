//dau mat'

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n, m;

    cin >> n;

    vector<ii> a1(n), a2(n);

    for (int i = 0; i < n; ++i)
    {
        int u, v; cin >> u >> v;
        a1[i].first = u, a1[i].second = v;
        a2[i].first = v, a2[i].second = u;
    }

    cin >> m;

    vector<ii> b1(m), b2(m);

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        b1[i].first = u, b1[i].second = v;
        b2[i].first = v, b2[i].second = u;
    }

    sort(a2.begin(), a2.end());
    sort(b1.rbegin(), b1.rend());

    int res = max(0, b1[0].first - a2[0].first);


    sort(a1.rbegin(), a1.rend());
    sort(b2.begin(), b2.end());

    res = max(res, a1[0].first - b2[0].first);

    cout << res;
}
