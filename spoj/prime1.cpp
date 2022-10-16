#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, r; cin >> n;

    while (n--)
    {
        cin >> l >> r;
        vector<bool> isPrime(r - l + 1, true);

        for (long long i = 2; i * i <= r; ++i)
        {
            for (long long j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
            {
                isPrime[j - l] = false;
            }
        }

        if (l <= 1) isPrime[1 - l] = false;

        for (long long i = l; i <= r; ++i)
        {
            if (isPrime[i - l]) cout << i << '\n';
        }

        cout << '\n';
    }
}
