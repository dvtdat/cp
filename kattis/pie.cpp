#include <bits/stdc++.h>
#define maxN 10010
#define M_PI 3.14159265358979

using namespace std;

double s[maxN];

bool check(double x, int n, int m)
{
    int cnt = 0;
    double sq = x * x * M_PI;
    for (int i = 0; i < n; ++i) cnt += floor(s[i] / sq);
    return (cnt >= m);
}

void solve()
{
    int n, m; cin >> n >> m;
    m++;

    for (int i = 0; i < n; ++i)
    {
        int rad; cin >> rad;
        s[i] = 1.0 * rad * rad * M_PI;
    }

    double l = 0, r = 10000, ans;

    for (int i = 0; i < 64; ++i)
    {
        double mid = (l + r) / 2;
        if (check(mid, n, m)) l = mid, ans = mid;
        else r = mid;
    }

    cout << fixed << setprecision(9) <<  ans * ans * M_PI << endl;
}

int main()
{
    int test;
    cin >> test;

    while (test--) solve();
}
