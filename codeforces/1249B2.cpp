// get lost?

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
    vector<int> p(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
        p[i]--;
    }

    vector<int> flag(n, 0);
    vector<int> res(n);

    for (int i = 0; i < n; ++i)
    {
        if (!flag[i])
        {
            vector<int> cur;
            while (!flag[i])
            {
                cur.push_back(i);
                flag[i] = 1;
                i = p[i];
            }

            for (int t : cur) res[t] = (int)cur.size();
        }
    }

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

