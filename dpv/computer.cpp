#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int a1, a2, a3, b1, b2, b3, ans = 0;

void convert(int &a, int &b)
{
    k = min(a, b);
    a -= k, b -= k;
    ans += k;
}

int main()
{
    freopen("computer.inp", "r", stdin);
    freopen("computer.out", "w", stdout);

    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    convert(a1, b1);
    convert(a2, b2);
    convert(a3, b1), convert(a3, b2);
    convert(a1, b3), convert(a2, b3), convert(a3, b3);

    cout << ans;

    return 0;
}
