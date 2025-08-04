//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 1e9 + 7;
const double eps = 1e-12;

ll fastPow(ll x, ll y) {
  ll result = 1;
  x %= MOD;

  while (y > 0) {
    if (y % 2 == 1)
      result = (result * x) % MOD;
    x = (x * x) % MOD;
    y /= 2;
  }
  return result;
}

void solve() {
  ll l, r, k; cin >> l >> r >> k;

  ll x = 0;
  for (ll i = 0; i < 10; ++i) {
    if (i * k < 10) x++;
  }

  // ll total = 0;

  // for (ll i = l; i < r; ++i) {
  //   total += (x - 1) * fastPow(x, i);
  //   total %= MOD;
  // }

  // cout << total << '\n';


  ll total = fastPow(x, l) * (fastPow(x, r - l) - 1);
  total %= MOD;
  cout << total << '\n';
}

void setIO(string name) {
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

int main() {
  setIO("text");
  int test; cin >> test;
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
