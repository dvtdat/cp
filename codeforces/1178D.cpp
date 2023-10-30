// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 2000010;
const ll MOD = 998244353;
const double eps = 1e-12;

vector<int> primes;
vector<bool> isPrime(maxN, true);

void sieve()
{
    isPrime[1] = false;
    for (int i = 2; i * i <= maxN; ++i)
    {
        if (!isPrime[i]) continue;
        primes.push_back(i);
        for (int j = i * i; j <= maxN; j += i) isPrime[j] = false;
    }
}

void solve()
{
    sieve();
    int n; cin >> n;
    int target = primes[lower_bound(primes.begin(), primes.end(), n) - primes.begin()];

    cout << target << '\n';
    for (int i = 1; i < n; ++i)
    {
        cout << i << ' ' << i + 1 << '\n';
    }
    cout << n << ' ' << 1 << '\n';

    for (int i = 2; i <= target - n + 1; ++i)
    {
        cout << i << ' ' << n + 2 - i << '\n';
    }
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("text");
    int test = 1; //cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//

