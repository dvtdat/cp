// doi' bung.

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void solve()
{
    int n, k; cin >> n;

    vector<ii> v;

    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        vector<int> a(k);
        for (int &i : a) cin >> i;

        int mx = 0;
        for (int i = 0; i < k; ++i)
        {
            mx = max(mx, a[i] - i);
        }

        v.push_back(ii(mx, k));
    }

    sort(v.begin(), v.end());

    int res = v[0].first, tmp = v[0].second;
    for (int i = 1; i < n; ++i)
    {
        res = max(res, v[i].first - tmp);
        tmp += v[i].second;
    }

    cout << res + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}
