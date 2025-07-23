//

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

vector<ll> getPrimes(ll maxValue = (ll) 9e6) {
  vector<ll> isPrime(maxValue + 1, 1);
  isPrime[0] = isPrime[1] = 0;
  for (ll i = 2; i * i <= maxValue; i++) {
    if (isPrime[i]) {
      for (ll j = i * i; j <= maxValue; j += i) {
        isPrime[j] = 0;
      }
    }
  }
  vector<ll> primeList;
  for (ll i = 2; i <= maxValue; i++) {
    if (isPrime[i]) {
      primeList.push_back(i);
    }
  }

  vector<ll> prefixPrimes(primeList.size());

  prefixPrimes[0] = primeList[0];
  for (ll i = 1; i < primeList.size(); ++i) {
    prefixPrimes[i] = prefixPrimes[i - 1] + primeList[i];
  }

  return prefixPrimes;
}

vector<ll> prefixPrimes;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n), prefix(n);

  for (ll& i : a)
    cin >> i;

  sort(a.rbegin(), a.rend());

  prefix[0] = a[0];
  for (ll i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1] + a[i];
  }

  ll res = 0;
  for (ll i = n - 1; i >= 0; --i) {
    // cout << prefix[i] << ' ' << prefixPrimes[i] << '\n';
    if (prefix[i] < prefixPrimes[i]) {
      res++;
    } else {
      cout << res << '\n';
      return;
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
  prefixPrimes = getPrimes();
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
