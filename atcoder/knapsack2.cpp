// mai em da roi xa nui' doi

#include <bits/stdc++.h>
#define N 110
#define M 100100
#define inf 1e11 + 1000

using namespace std;

long long f[M];
long long a[N], v[N];

int main()
{
    long long n, w; cin >> n >> w;

    long long m  = 0;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i] >> v[i];
        m += v[i];
    }

    for (long long i = 0; i <= m; ++i) f[i] = inf;

    f[0] = 0;
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = m - v[i]; j >= 0; --j)
        {
            if (f[j] != inf || j == 0) f[j + v[i]] = min(f[j + v[i]], f[j] + a[i]);
        }
    }

    for (long long i = m; i >= 0; --i)
    {
        if (f[i] <= w && f[i] != 0)
        {
            cout << i;
            return 0;
        }
    }

}

