// mao phac'

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

bool a[maxN];

void solve()
{
    memset(a, false, sizeof a);
    int n; cin >> n;
    int sum = 0;

    int cntOne = 0, cntZero = 0;
    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        if (c == 'B') a[i] = 1, cntOne++;
        else a[i] = 0, cntZero++;
        sum += (int)a[i];
    }

    if (cntZero & 1 && cntOne & 1)
    {
        cout << -1 << '\n';
        return;
    }
    
    if (sum == 0 || sum == n)
    {
        cout << 0 << '\n';
        return;
    }

    if (cntZero % 2 == 0)
        for (int i = 0; i < n; ++i) a[i] ^= 1;

    vector<int> res;
    int i = 0;
    while (i < n)
    {
        if (a[i])
        {
            res.push_back(i + 1);
            while (!a[i + 1] && i + 1 < n)
            {
                i++;
                res.push_back(i + 1);
            }
            a[i + 1] = 0;
        }
        i++;
    }

    cout << res.size() << '\n';
    for (int i : res) cout << i << ' ';

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
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

