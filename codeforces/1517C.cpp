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
const int maxN = 1010;
const ll MOD = 998244353;
const double eps = 1e-12;

int a[maxN][maxN];
int n;

bool check(int x, int y)
{
    return (x > 0 && y > 0 && x <= n && y <= n);
}

void solve()
{
    memset(a, -1, sizeof a);
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i][i];

    for (int k = 1; k <= n; ++k)
    {
        int cnt = a[k][k] - 1;
        int j = k, i = k;
        
        while (cnt)
        {
            while (a[i][j - 1] == -1 && check(i, j - 1) && cnt)
            {
                j--;
                a[i][j] = a[k][k];
                cnt--;
            }

            while ((a[i][j - 1] != -1 || !check(i, j - 1)) && cnt)
            {
                i++;
                a[i][j] = a[k][k];
                cnt--;
            }
        }
        
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j) cout << a[i][j] << ' ';
        cout << '\n';
    }
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

