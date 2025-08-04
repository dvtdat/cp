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

map<string, int> _m;
vector<string> type;


vector<int> compatible(string s) {
  vector<int> tmp;
  if (s.find('B') != string::npos) {
    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(2);
  }
  if (s.find('R') != string::npos) {
    tmp.push_back(1);
    tmp.push_back(3);
    tmp.push_back(5);
  }
  if (s.find('Y') != string::npos) {
    tmp.push_back(2);
    tmp.push_back(4);
    tmp.push_back(5);
  }
  if (s.find('G') != string::npos) {
    tmp.push_back(0);
    tmp.push_back(3);
    tmp.push_back(4);
  }
  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  return tmp;
}

void solve() {
  int n, q; cin >> n >> q;

  vector<string> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<vector<int> > left(6, vector<int>(n, -1));
  vector<vector<int> > right(6, vector<int>(n, -1));

  for (int t = 0; t < type.size(); ++t) {
    for (int i = 0; i < n; ++i) {
      if (a[i] == type[t]) left[t][i] = i;
      else if (i > 0) left[t][i] = left[t][i - 1];
      else left[t][i] = -1;
    }
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] == type[t]) right[t][i] = i;
      else if (i < n - 1) right[t][i] = right[t][i + 1];
      else right[t][i] = -1;
    }
  }

  while (q--) {
    int u, v; cin >> u >> v;
    u--;
    v--;

    vector<int> cU = compatible(a[u]);
    vector<int> cV = compatible(a[v]);

    if (find(cU.begin(), cU.end(), _m[a[v]]) != cU.end()) {
      cout << abs(u - v) << '\n';
      continue;
    }

    vector<int> common;
    set_intersection(cU.begin(), cU.end(), cV.begin(), cV.end(), back_inserter(common));

    if (u > v) swap(u, v);

    int res = inf;
    for (int type : common) {
      if (right[type][u] >= 0 && right[type][u] <= v) {
        res = min(res, abs(u - v));
      }

      if (right[type][u] >= 0 && right[type][v] >= 0) {
        int z = right[type][v];
        res = min(res, abs(z - u) + abs(z - v));
      }

      if (left[type][u] >= 0 && left[type][v] >= 0) {
        int z = left[type][u];
        res = min(res, abs(u - z) + abs(v - z));
      }
    }

    if (res == inf) {
      cout << -1 << '\n';
    } else {
      cout << res << '\n';
    }
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
  type.push_back("BG");
  type.push_back("BR");
  type.push_back("BY");
  type.push_back("GR");
  type.push_back("GY");
  type.push_back("RY");

  _m["BG"] = 0;
  _m["BR"] = 1;
  _m["BY"] = 2;
  _m["GR"] = 3;
  _m["GY"] = 4;
  _m["RY"] = 5;
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
