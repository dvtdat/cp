#include <bits/stdc++.h>
#define maxN 10000010

using namespace std;

int sum[maxN];

int main()
{
    freopen("HHH.INP", "r", stdin);
    freopen("HHH.OUT", "w", stdout);

    int a, b;
    cin >> a >> b;

    for (int d = 1; d <= b; ++d)
    {
        int mul = 2;

        while (mul <= b / d)
        {
            sum[d * mul] += d;
            mul++;
        }
    }

    long long res = 0;
    for (int i = a; i <= b; ++i) res += abs(sum[i] - i);

    cout << res;
}
