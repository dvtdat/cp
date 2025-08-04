//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 1e9 + 7;
const double eps = 1e-12;

// NOT DONE
void solve() {
  int n, m; cin >> n >> m;
  vector<ii> a(n + m + 1);

  for (ii& i : a) cin >> i.first;
  for (ii& i : a) cin >> i.second;

  vector<ii> p(n + m + 1);
  for (int i = 0; i < n + m + 1; ++i) {
    p[i].first = a[i].first - a[i].second;
    p[i].second = i;
  }

  sort(p.rbegin(), p.rend());

  vector<int> res(n + m + 1, -1);

  int sum = 0;
  for (int i = 0; i < n + m + 1; ++i) {
    if (i <= n) sum += a[p[i].second].first;
    else sum += a[p[i].second].second;
  }

  for (int i = 0; i < n + m + 1; ++i) {
    if (i <= n) {
      // cout << "debug: " << a[p[i].second].first << ' ' << a[p[i].second].second << '\n';
      res[p[i].second] = sum - a[p[i].second].first;
    } else {
      res[p[i].second] = sum - a[p[n].second].first + a[p[n].second].second - a[p[i].second].second;
    }
  }

  for (int i : res) cout << i << ' ';
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
