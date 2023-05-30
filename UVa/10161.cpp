#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    while (cin >> k && k != 0)
    {
        int n = (int)ceil(sqrt(k));

        int i = 0;
        int j = 0;

        if (n * n >= k && k >= n * n + 1 - n)
        {
            j = n * n + 1 - k;
            i = n;
        }
        else if ((n - 1) * (n - 1) + 1 <= k && k <= (n - 1) * (n - 1) + n)
        {
            j = n;
            i = k - (n - 1) * (n - 1);
        }

        if (n % 2) swap(i, j);
        cout << i << ' ' << j << '\n';
    }
}