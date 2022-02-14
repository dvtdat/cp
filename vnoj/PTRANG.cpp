//my eyes do hurt alot ;(

#include <bits/stdc++.h>
#define N 6100
#define inf INT_MAX

using namespace std;
int a[N], p[N], f[N];

int main()
{
    int n, l; cin >> n >> l;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    p[0] = 0; p[1] = a[1];
    for (int i = 2; i <= n; ++i) p[i] = p[i - 1] + a[i];

    f[0] = 0; f[1] = l - a[1];
    for (int i = 2; i <= n; ++i)
    {
        f[i] = inf;
        for (int j = 0; j <= i; ++j)
        {
            if (p[i] - p[j - 1] <= l)
            {
                f[i] = min(f[i], max(f[j - 1], l - (p[i] - p[j - 1])));
            }
        }
    }

    cout << f[n];
}
