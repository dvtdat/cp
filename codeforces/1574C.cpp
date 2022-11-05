// hustle?

// lmao khong hieu sao code dc bai` nay` luon
// lam` tao` lao nhung van~ AC kek
// cha? hieu? kieu? gi`

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const ll inf = 2e18 + 7;
const int maxN = 200010;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);

    for (ll &i : a) cin >> i;
    sort(a.begin(), a.end());

    ll sum = 0;
    for (ll i : a) sum += i;

    int m; cin >> m;

    while (m--)
    {
        ll x, y; cin >> x >> y;
        ll res = inf;

        int lower = lower_bound(a.begin(), a.end(), x) - a.begin();
        int upper = upper_bound(a.begin(), a.end(), x) - a.begin();

        if (lower == n) lower--;
        else if (lower == upper) lower--;
        if (upper == n) upper--;

        res = min(res, max(0LL, x - a[upper]) + max(0LL, y - (sum - a[upper])));
        res = min(res, max(0LL, x - a[lower]) + max(0LL, y - (sum - a[lower])));

        cout << res << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}
