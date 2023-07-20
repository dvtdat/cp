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

    vector<int> x(n + 2), h(n + 2);
    vector<bool> left(n + 2, false), right(n + 2, false), non(n + 2, true);

    for (int i = 1; i <= n; ++i) cin >> x[i] >> h[i];

    x[0] = -inf;
    x[n + 1] = inf;
    left[1] = true;
    non[1] = false;

    int res = 0;

    for (int i = 1; i <= n; ++i)
    {
        if ((left[i - 1] || non[i - 1]) && x[i] - h[i] > x[i - 1])
        {
            left[i] = true; non[i] = false;
            res++;
        }
        
        if (right[i - 1] && x[i] - h[i] > x[i - 1] + h[i - 1])
        {
            left[i] = true; non[i] = false;
            res++;
        }
        
        if (non[i] && x[i] + h[i] < x[i + 1])
        {
            right[i] = true; non[i] = false;
            res++;
        }

        // cout << res << ' ' << x[i] << '\n';
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

