// 

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

int a[maxN];

void solve()
{
    int n; cin >> n;

    memset(a, 0, sizeof a);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    ll res = 0;
    int cur = 0, prev = 0, cntCur = 0, cntPrev = 0;

    int i = 0;
    while (i < n)
    {
        cur = a[i];
        cntCur = 0;

        if (cur != prev + 1) 
        {
            cntPrev = 0;
        }
        
        while (a[i] == cur) 
        {
            i++; cntCur++;
        }

        res += 1LL * max(0, cntCur - cntPrev);
        cntPrev = cntCur;
        prev = cur;
    }

    cout << res << '\n';
    
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

