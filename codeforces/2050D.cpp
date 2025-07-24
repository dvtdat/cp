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
  string s; cin >> s;
  int n = s.length();

  vector<int> a(n), mark(n, 0), f(n, 0);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
  }


  for (int i = 0; i < n; ++i) {
    int curr = a[i];
    int idx = i;
    for (int k = 1; k <= 9; ++k) {
      if (i + k >= n) continue;
      if (a[i + k] - k > curr) {
        curr = a[i + k] - k;
        idx = i + k;
      }
    }

    while (idx > i) {
      swap(a[idx], a[idx - 1]);
      idx--;
    }

    a[i] = curr;
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i];
  }
  cout << "\n";
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
