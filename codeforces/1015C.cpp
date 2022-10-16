#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    vector<int> a(n);

    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int u, v; cin >> u >> v;
        sum += u * 1LL;
        a[i] = abs(v - u);
    }

    sort(a.rbegin(), a.rend());

    int cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        if (sum <= m)
        {
            cout << i;
            return 0;
        }

        sum -= a[i];
    }

    if (sum <= m) cout << n;
    else cout << -1;

}
