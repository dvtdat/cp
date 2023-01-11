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
const int maxN = 200100;
const ll MOD = 998244353;
const double eps = 1e-12;

int val[3000], ok[100], a[100][100];
int n;
int td = {0, 0, 1, -1};
int tc = {-1, 1, 0, 0};

bool check(int x, int y)
{
    return (x > 0 && x < n && y > 0 && y < n);
}

void solve()
{
    cin >> n;
    // NOT DONE YET FUCK MY LIFE
    memset(a, 0, sizeof a);
    memset(val, 0, sizeof val);

    a[0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            for (int k = n * n - 1; k > 0; --k)
            {
                if (val[k] == 0 && a[i][j - 1] - k > 0 && (!ok[a[i][j - 1] + k] || !ok[a[i][j - 1] - k]))
                {
                    val[k] = 1;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test = 1; cin >> test;
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


