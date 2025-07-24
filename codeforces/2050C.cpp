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

  int sum = 0;
  int cnt2 = 0, cnt3 = 0;

  for (char c : s) {
    int d = c - '0';
    sum += d;
    if (d == 2) cnt2++;
    else if (d == 3) cnt3++;
  }

  for (int i = 0; i <= min(10, cnt2); ++i) {
    for (int j = 0; j <= min(10, cnt3); ++j) {
      if ((sum + i * 2 + j * 6) % 9 == 0) {
        cout << "yes\n";
        return;
      }
    }
  }

  cout << "no\n";
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
