#include <iostream>
#include <cmath>

using namespace std;

/* Find number of digits of nCk */

int main()
{
    unsigned long long n, k;
    while (cin >> n >> k)
    {
        long double res = 0;
        for (unsigned long long i = k + 1; i <= n; ++i) res += log10((double)i);
        for (unsigned long long i = 1; i <= n - k; ++i) res -= log10((double)i);

        cout << (int)res + 1 << '\n';
    }
    return 0;
}