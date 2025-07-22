// it's been a long time

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
  string s, t;
  cin >> s >> t;

  int i = 0, j = 0;

  while (i < s.length() && j < t.length())
  {
    if (s[i] == '?' || s[i] == t[j])
    {
      s[i] = t[j];
      j++;
    }
    i++;
  }

  i = 0;
  j = 0;

  while (i < s.length() && j < t.length())
  {
    while (i < s.length() && t[j] != s[i])
    {
      i++;
    }

    if (i >= s.length())
      break;

    j++;
    i++;
  }

  // cout << s << ' ' << t << '\n';
  // cout << i << ' ' << j << '\n';

  if (j != t.length())
  {
    cout << "NO\n";
  }
  else
  {
    cout << "YES\n";
    for (int i = 0; i < s.length(); ++i)
    {
      if (s[i] == '?')
        s[i] = 'z';
    }
    cout << s << '\n';
  }
}

void setIO(string name)
{
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

int main()
{
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
