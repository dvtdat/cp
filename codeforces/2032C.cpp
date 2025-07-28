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
  int n; cin >> n;
  vector<int> a(n);

  for (int& i : a) cin >> i;

  sort(a.begin(), a.end());

  int res = inf;
  for (int i = 1; i < n - 1; ++i) {
    auto it = lower_bound(a.begin(), a.end(), a[i - 1] + a[i]);
    int left = i - 1, right;
    if (it == a.end()) {
      right = 0;
    } else {
      right = distance(it, a.end());
    }
    // cout << "i: " << i << "; sum: " << a[i - 1] + a[i] << "; left: " << left << "; right: " << right << '\n';
    res = min(res, left + right);
  }

  cout << res << '\n';
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
