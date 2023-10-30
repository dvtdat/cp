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

    int left = inf, leftCost = inf;
    int right = 0, rightCost = inf;
    int mxLen = 0, lenCost = inf;
    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        int u, v, w; cin >> u >> v >> w;

        if (u < left) left = u, leftCost = inf;
        if (u == left) leftCost = min(leftCost, w);

        if (v > right) right = v, rightCost = inf;
        if (v == right) rightCost = min(rightCost, w);

        if (mxLen < v - u + 1) mxLen = v - u + 1, lenCost = inf;
        if (mxLen == v - u + 1) lenCost = min(lenCost, w);
        
        res = leftCost + rightCost; 
        if (mxLen == right - left + 1) res = min(lenCost, res);

        cout << res << '\n';
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

