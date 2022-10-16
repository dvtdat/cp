#include <bits/stdc++.h>

using namespace std;

const int maxN = 100000;

int sum[maxN + 5];

void sieve()
{
    for (int i = 1; i <= maxN; ++i)
    {
        for (int j = i + i; j <= maxN; j += i)
        {
            sum[j] += i;
        }
    }
}

int main()
{
    sieve();

    int l, r; cin >> l >> r;

    int res = 0;
    for (int i = l; i <= r; ++i)
    {
        if (i < sum[i]) res++;
    }

    cout << res;
}
