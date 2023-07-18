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

void solve()
{
    int n; cin >> n;
    
    int cur = 0, mx = 0, cnt = 0;
    bool male = true;

    for (int i = 0; i < n; ++i)
    {
        int u; cin >> u;
        if (u == 1)
        {
            if (!male) cnt++;
            male = false;
            cur++;
            mx = max(cur, mx);
        }
        else if (u == 2)
        {
            mx = max(cur, mx);
            cur = (cnt + 1) / 2 + (!male ? 1 : 0);
        }
    }

    cout << mx << '\n';
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

