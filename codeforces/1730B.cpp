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
const double eps = 1e-7;

bool check(double m, vector<int> x, vector<int> t)
{
    double mn = 0.0, mx = 2e9;

    for (int i = 0; i < x.size(); ++i)
    {
        double xR = 1.0 * x[i] + m - t[i];
        double xL = 1.0 * x[i] - m + t[i];

        if (xR < mn || mx < xL) return false;
        mx = min(xR, mx);
        mn = max(xL, mn);
    }
    // cout << mn << ' ' << mx << '\n';

    if (mn > mx) return false;
    return true;
}

void solve()
{
    int n; cin >> n;

    vector<int> t(n);
    vector<int> x(n);

    for (int &i : x) cin >> i;
    for (int &i : t) cin >> i;

    double l = 0.0, r = 2e9;
    double res = 0;

    while (r - l > eps)
    {
        double mid = l + (r - l) * 0.5f;
        if (check(mid, x, t)) r = mid, res = mid;
        else l = mid;
        // cout << mid << '\n';
    }

    double mn = 0.0, mx = 2e9;

    for (int i = 0; i < x.size(); ++i)
    {
        double xR = 1.0 * x[i] + res - t[i];
        double xL = 1.0 * x[i] - res + t[i];

        mx = min(xR, mx);
        mn = max(xL, mn);
    }

    cout << mn << '\n';
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
    cout << fixed << setprecision(1);
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

