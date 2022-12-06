// em xinh lam nhung em dau co' la` cua? toi dau :(

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
    int sum = 0, mx = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
        mx = max(mx, a[i].first);
        sum += (a[i].first + 1) / 2;
    }

    if (sum > k)
    {
        cout << -1; return;
    }

    sort(a.rbegin(), a.rend());
    vector<ii> b(n);

    for (int i = 0; i < n; ++i)
    {
        b[i].first = a[i].second;
        b[i].second = (a[i].first + 1) / 2;

        if (k - sum > 0) b[i].second = min(a[i].first, b[i].second + k - sum);
        k -= b[i].second;
        sum -= (a[i].first + 1) / 2;
    }

    sort(b.begin(), b.end());

    for (ii i : b) cout << i.second << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//

