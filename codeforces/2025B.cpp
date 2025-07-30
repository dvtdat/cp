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

void solve() {
  ll n; cin >> n;

  vector<ll> a(n), k(n);
  for (ll& i : a) cin >> i;
  for (ll& i : k) cin >> i;

  vector<ll> res((int) 1e5 + 10);

  res[0] = 1;
  for (int i = 1; i < 1e5 + 10; ++i) {
    res[i] = res[i - 1] * 2;
    res[i] %= MOD;
  }

  for (int i : k) {
    cout << res[i] << '\n';
  }
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
  int test = 1;
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
