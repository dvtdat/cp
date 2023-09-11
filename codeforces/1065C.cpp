// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    ll n, k; cin >> n >> k;

    vector<ll> a(n), b(maxN, 0);

    ll mn = inf, mx = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[a[i]]++;

        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    if (mx == mn)
    {
        cout << 0 << "\n";
        return;
    }

    int i = maxN - 1;
    int cnt = 0;
    ll total = 0;
    ll c = 0;

    while (true)
    {
        ll tmp = total - 1LL * c * (i - 1);

        if (tmp > k)
        {
            cnt++;
            mx = i;
            total = 1LL * i * c;
        }

        i--;

        if (i == mn) break;
        c += b[i];
        total += 1LL * b[i] * i;
    }

    if (mx != mn) cnt++;

    cout << cnt << '\n';
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("text");
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

