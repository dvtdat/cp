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
  ll n; cin >> n;
  vector<ll> a(n);

  for (ll& i : a) cin >> i;

  ll sumOdd = 0;
  ll sumEven = 0;

  for (ll i = 0; i < n; ++i) {
    if (i % 2 == 0) sumEven += a[i];
    else sumOdd += a[i];
  }

  if (sumEven % ((n + 1) / 2) == 0 && sumOdd % (n / 2) == 0 && sumEven / ((n + 1) / 2) == sumOdd / (n / 2)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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
