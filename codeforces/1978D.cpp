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
  ll n, c; cin >> n >> c;

  vector<ll> a(n), prefix(n);

  for (ll& i : a) cin >> i;

  a[0] += c;
  prefix[0] = a[0];
  for (ll i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1] + a[i];
  }

  ll winner = -1;
  ll mx = 0;

  for (ll i = 0; i < n; ++i) {
    if (mx < a[i]) {
      mx = a[i];
      winner = i;
    }
  }

  vector<ll> res;
  for (ll i = 0; i < n; ++i) {
    if (winner == i) {
      res.push_back(0);
      continue;
    }

    ll sum = a[i] + ((i == 0) ? 0 : prefix[i - 1]);
    // cout << "Sum: " << sum << "\n";

    if (sum >= a[winner] || winner < i) {
      res.push_back(i);
    } else {
      res.push_back(i + 1);
    }
  }

  for (ll i : res) cout << i << ' ';
  cout << '\n';
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
  int test = 1; cin >> test;
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
