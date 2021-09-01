#include <bits/stdc++.h>

using namespace std;

long long f[10010];

int main()
{
    int n;
    long long k;
    cin >> n >> k;

    f[0] = 0; f[1] = 1; f[2] = 1;

    n = min(n, 90);

    for (int i = 2; i <= n; ++i) f[i] = f[i - 1] + f[i - 2];

    while (n > 2)
    {
        if (k > f[n - 2]) k -= f[n - 2], n--;
        else n -= 2;
    }

    if (n == 1) cout << 'N'; else cout << 'A';
}
