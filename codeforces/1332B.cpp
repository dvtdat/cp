// hungry but must not eat

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 2010;
const ll MOD = 998244353;
const double eps = 1e-12;

int num[maxN];
int print[maxN];

void sieve()
{
    memset(num, 0, sizeof num);
    int cnt = 0;
    for (int i = 2; i * i <= 1000; ++i)
    {
        if (num[i]) continue;
        cnt++;
        for (int j = i * i; j <= 1000; j += i)
        {
            num[j] = cnt;
        }
    }
}

int check[12];

void solve()
{
    memset(check, 0, sizeof check);

    int n; cin >> n;
    vector<int> inp(n);
    int cnt = 0;

    for (int i = 0; i < n; ++i) 
    {
        cin >> inp[i];
        if (check[num[inp[i]]]) continue;
        cnt++; check[num[inp[i]]] = cnt;  
    }

    cout << cnt << '\n';
    for (int i = 0; i < n; ++i)
    {
        cout << check[num[inp[i]]] << ' ';
    }
    cout << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    sieve();
    int test; cin >> test;
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

