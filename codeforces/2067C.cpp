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

  int mn = INT_MAX, mnIdx = 7;
  for (int k = 0; k <= 7; ++k) {
    int nn = n - k;
    vector<int> a;
    int x = nn;
    while (x != 0) {
      a.push_back(x % 10);
      x /= 10;
    }

    bool flag = a[0] == 7;
    for (int i = 1; i < a.size(); ++i) {
      if ((17 - a[i]) % 10 <= k) flag = true;
    }

    if (flag) {
      mnIdx = min(mnIdx, k);
    }
  }

  cout << mnIdx << '\n';
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
