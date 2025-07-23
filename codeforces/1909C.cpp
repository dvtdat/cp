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
  ll n;
  cin >> n;

  vector<ll> a(n), b(n), c(n);
  vector<ii> p;

  for (ll& i : a)
    cin >> i;
  for (ll& i : b)
    cin >> i;
  for (ll& i : c)
    cin >> i;

  for (int i = 0; i < n; ++i) {
    p.push_back(ii(a[i], 1));
    p.push_back(ii(b[i], 2));
  }

  sort(c.rbegin(), c.rend());
  sort(p.begin(), p.end());

  stack<ll> st;
  ll x = 0, sum = 0;

  vector<ll> res;
  for (int i = 0; i < n * 2; ++i) {
    if (p[i].second == 2) {
      res.push_back(p[i].first - st.top());
      st.pop();
    } else {
      st.push(p[i].first);
    }
  }

  sort(res.begin(), res.end());
  for (int i = 0; i < n; ++i) sum += res[i] * c[i];

  cout << sum << '\n';
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
