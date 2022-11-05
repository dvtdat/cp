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

    vector<ii> a(n);

    for (ii &i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end());

    int i = 0, j = 0;
    ll res = 0;
    ll tmp = 0;

    while (i < n)
    {
        while (j < n && a[j].first - a[i].first < k)
        {
            tmp += a[j++].second;
        }

        res = max(res, tmp);
        tmp -= a[i++].second;
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}


