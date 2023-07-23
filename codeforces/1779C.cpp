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
    priority_queue<ll> pMax, pMin;

    ll n, k; cin >> n >> k;
    ll res = 0;
    k--;

    vector<ll> a(n);
    vector<ll> p(n, 0);

    for (ll i = 0; i < n ; ++i) cin >> a[i];

    ll i = k;
    ll sum = 0;
    while (i >= 1)
    {
        sum += a[i];
        pMax.push(a[i]);
        while (sum > 0)
        {
            sum -= pMax.top() * 2;
            pMax.pop();
            res++;
        }
        i--;
    }
    
    i = k + 1;
    sum = 0;
    while (i < n)
    {
        sum += a[i];
        pMin.push(-a[i]);
        while (sum < 0)
        {
            sum += pMin.top() * 2;
            pMin.pop();
            res++;
        }
        i++;
    }

    cout << res << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
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
