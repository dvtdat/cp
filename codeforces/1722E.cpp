// 

#include <bits/stdc++.h>

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

ll a[maxN][maxN];
ll prefix[maxN][maxN];

void solve()
{
    memset(a, 0, sizeof a);
    memset(prefix, 0, sizeof prefix);

    int n, q; cin >> n >> q;
    
    for (int i = 0; i < n; ++i)
    {
        ll h, w; cin >> h >> w;
        a[h][w] += h * w;
    }

    for (int i = 0; i < maxN - 3; ++i)
    {
        for (int j = 0; j < maxN - 3; ++j)
        {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
        }
    }

    while (q--)
    {
        ll hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        cout << prefix[hb - 1][wb - 1] - prefix[hb - 1][ws] - prefix[hs][wb - 1] + prefix[hs][ws] << '\n';
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

