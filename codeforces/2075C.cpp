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
const ll MOD = 998244353;
const double eps = 1e-12;

void solve() {
  ll n, k; cin >> k >> n;
  vector<ll> a(n);

  for (ll& i : a) cin >> i;

  for (ll i = 0; i < n; ++i) {
    a[i] = max(a[i], 1ll);
    a[i] = min(a[i], k - 1ll);
  }

  sort(a.begin(), a.end());

  vector<ll> prefix(n);
  prefix[0] = a[0];
  for (ll i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1] + a[i];
  }

  ll total = 0;
  for (ll i = 0; i < n; ++i) {
    ll m = k - a[i];

    auto it = lower_bound(a.begin(), a.end(), m);
    if (it == a.end()) {
      continue;
    } else {
      ll idx = distance(a.begin(), it);
      ll x = n - idx - (idx <= i ? 1 : 0);
      ll sum = prefix[n - 1] - (idx > 0 ? prefix[idx - 1] : 0) - (idx <= i ? a[i] : 0);
      sum += x * (a[i] - k + 1);
      total += sum;
    }
  }

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
