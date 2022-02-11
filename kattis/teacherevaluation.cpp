#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, sum = 0;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        int tmp; cin >> tmp;
        sum += tmp;
    }

    if (sum > n * k)
    {
        cout << 0; return 0;
    }

    if (k == 100)
    {
        cout << "impossible"; return 0;
    }

    int i = n;
    while (sum != i * k)
    {
        i++;
        sum += min(100, i * k - sum);
    }

    cout << i - n;
}
