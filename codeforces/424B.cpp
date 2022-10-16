// gdsc?

#include <bits/stdc++.h>

using namespace std;

typedef pair<double, int> ii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s; cin >> n >> s;

    vector<ii> a(n);

    for (int i = 0; i < n; ++i)
    {
        int u, v; cin >> u >> v >> a[i].second;
        a[i].first = 1.0 * sqrt(1.0 * u * u + 1.0 * v * v);
    }

    sort(a.begin(), a.end());

    double res = 0;

    cout << fixed << setprecision(7);

    for (int i = 0; i < n; ++i)
    {
        if (s >= 1000000)
        {
            cout << res;
            return 0;
        }

        s += a[i].second;
        res = a[i].first;
    }

    if (s >= 1000000) cout << res;
    else cout << -1;
}
