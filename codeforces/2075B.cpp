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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);

  for (ll &i : a)
    cin >> i;

  if (k >= 2)
  {
    sort(a.rbegin(), a.rend());
    ll sum = 0;
    for (ll i = 0; i < min(k + 1, n); ++i)
    {
      sum += a[i];
    }

    cout << sum << '\n';
  }
  else
  {
    ll mx1 = 0, mx2 = 0;
    for (ll i = 0; i < n - 1; ++i)
      mx1 = max(mx1, a[i]);
    for (ll i = 1; i < n; ++i)
      mx2 = max(mx2, a[i]);

    cout << max(mx1 + a[n - 1], mx2 + a[0]) << '\n';
  }
}

void setIO(string name)
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  if (!name.size())
    return;

#ifndef ONLINE_JUDGE
  freopen((name + ".inp").c_str(), "r", stdin);
  // freopen((name + ".out").c_str(), "w", stdout);
#endif
}

int main()
{
  setIO("text");
  int test;
  cin >> test;
  while (test--)
    solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//
