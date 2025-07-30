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

// NOT DONE
void solve() {
  int n; cin >> n;
  int k; cin >> k;

  vector<vector<int> > f(k + 5, vector<int>(k + 5, -1));
  vector<int> a(n);

  for (int& i : a) cin >> i;

  int cnt = 0;
  int gain = 0;
  int mx = 0;
  f[0][0] = 0;

  for (int value : a) {
    if (value == 0) {
      gain++;
      continue;
    }

    vector<vector<int> > ff = f;

    for (int i = 0; i <= cnt; ++i) {
      for (int j = 0; j <= cnt; ++j) {
        if (f[i][j] == -1) continue;

        for (int ii = i; ii <= i + gain; ++ii) {
          int jj = gain - ii + j;

          if (ii > k || jj > k) continue;

          int tmp = f[i][j];
          if (value < 0) {
            tmp += (jj >= -value ? 1 : 0);
          } else {
            tmp += (ii >= value ? 1 : 0);
          }

          ff[ii][jj] = max(ff[ii][jj], tmp);
          mx = max(mx, ff[ii][jj]);
        }
      }
    }

    f = ff;
    cnt += gain;
    gain = 0;
  }

  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= k; ++j) cout << f[i][j] << ' ';
    cout << '\n';
  }

  cout << mx << '\n';
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
