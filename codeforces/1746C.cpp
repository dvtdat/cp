// croatia 0 - 0 brazil (H1)

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
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n; cin >> n;

    int cnt = 1;
    vector<int> a(n), diff(n);

    for (int &i : a) cin >> i;

    for (int i = 1; i < n; ++i)
    {
        diff[i] = max(0, a[i - 1] - a[i]);
    }

    vector<int> res1, res2;

    for (int i = n - 1; i > 0; --i)
    {
        int sum = 0;
        while (diff[i] != 0 && sum < diff[i])
        {
            sum += cnt++;
            res1.push_back(i + 1);
        }
    }

    while (res1.size() < n) res1.push_back(1);

    cnt = 1;
    for (int i = 1; i < n; ++i)
    {
        int sum = 0;
        while (diff[i] != 0 && sum < diff[i])
        {
            sum += cnt++;
            res2.push_back(i + 1);
        }
    }

    while (res1.size() < n) res1.push_back(1);
    while (res2.size() < n) res2.push_back(1);

    vector<int> res;

    if (res2.size() < res1.size()) res = res2;
    else res = res1;
    
    for (int i : res) cout << i << ' ';
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

