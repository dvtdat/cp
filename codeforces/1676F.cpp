// roi ngta se yeu m thoi

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

    vector<int> a(n);
    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    vector<int> b;

    int cnt = 1;

    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            if (cnt >= k) b.push_back(a[i - 1]);
            cnt = 1;
        }
        else if (a[i] == a[i - 1]) cnt++;
    }

    if (cnt >= k) b.push_back(a[n - 1]);

    if (b.empty())
    {
        cout << -1 << '\n';
        return;
    }

    int l, r;
    l = r = b[0];

    vector<iii> res;

    for (int i = 1; i < b.size(); ++i)
    {
        if (b[i] != b[i - 1] + 1)
        {
            res.push_back(iii(r - l, ii(l, r)));
            l = r = b[i];
        }
        else r = b[i];
    }

    res.push_back(iii(r - l, ii(l, r)));

    sort(res.rbegin(), res.rend());
    cout << res[0].second.first << ' ' << res[0].second.second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}

