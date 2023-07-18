// tien cua con khong co' can phai? rua?

#include <bits/stdc++.h>
#define N 110
#define M 100100
#define inf 1e18

using namespace std;

//long long f[N][M];
long long f[M];
long long a[N], v[N];

int main()
{
    long long n, w; cin >> n >> w;

    v[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> v[i];

//    memset(f, 0, sizeof f);
//
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 0; j <= w; ++j)
//        {
//            f[i][j] = f[i - 1][j];
//            if (j - a[i] >= 0) f[i][j] = f[i - 1][j - a[i]] + v[i];
//        }
//    }

    memset(f, 0, sizeof f);

    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = w - a[i]; j >= 0; --j)
        {
            if (f[j] || j == 0) f[j + a[i]] = max(f[j + a[i]], f[j] + v[i]);
        }
    }

    long long res = 0;
    for (long long i = 0; i <= w; ++i) res = max(res, f[i]);

    cout << res;
}
