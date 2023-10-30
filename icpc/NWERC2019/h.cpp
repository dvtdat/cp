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
const double eps = 1e-6;

int n, k;
int h[maxN];
int gSeg[maxN];
ii y[maxN];
ii p[maxN];
int g;
int maxG;

void solve()
{
    memset(y, 0, sizeof y);
    memset(p, 0, sizeof p);

    float x; cin >> x; x *= 10;
    g = x;

    if (maxG < g)
    {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i <= n; ++i)
    {
        y[i] = ii(h[i] - g * i, i);
        p[i] = y[i];
    }

    double res = -1.0;
    sort(y, y + n + 1);

    int l = n, r = 0;

    for (int i = 0; i <= n; ++i)
    {
        r = y[i].second;
        if (l < r) 
        {
            double tmp = 0.0;
            if (l > 0)
            {
                tmp = max(tmp, (double)(p[r].first - p[l].first) / fabs(p[l].first - p[l - 1].first));
            }

            if (r < n)
            {
                tmp = max(tmp, (double)(p[r].first - p[l].first) / fabs(p[r + 1].first - p[r].first));
            }

            if (tmp > 1.0) tmp = 1.0;
            res = max(res, r - l + tmp);

        }
        l = min(l, r);
    }

    cout << res << '\n';
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
    cout << fixed << setprecision(12);
    setIO("text");

    cin >> n >> k;
    for (int i = 0; i <= n; ++i) cin >> h[i];
    for (int i = 0; i <= n; ++i) maxG = max(maxG, h[i + 1] - h[i]);

    while (k--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//


