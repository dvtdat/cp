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
  ll k; cin >> k;
  vector<ll> a(n);

  for (ll& i : a) cin >> i;
  sort(a.begin(), a.end());

  map<ll, ll> cnt;
  for (ll i : a) {
    cnt[i]++;
  }

  a.erase(unique(a.begin(), a.end()), a.end());

  vector<vector<ll> > mark;
  mark.push_back(vector<ll>());
  mark[0].push_back(a[0]);
  ll j = 0;

  for (ll i = 0; i < n; ++i) {
    if (a[i] != mark[j].back() + 1) {
      mark.push_back(vector<ll>());
      mark[++j].push_back(a[i]);
    } else {
      mark[j].push_back(a[i]);
    }
  }

  ll res = 0;
  for (ll x = 0; x < mark.size(); ++x) {
    ll sum = 0;
    for (ll i = 0; i < min((ll) mark[x].size(), k); ++i) {
      sum += cnt[mark[x][i]];
    }
    res = max(res, sum);

    for (ll i = k; i < mark[x].size(); ++i) {
      sum += cnt[mark[x][i]];
      sum -= cnt[mark[x][i - k]];
      res = max(res, sum);
    }
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
