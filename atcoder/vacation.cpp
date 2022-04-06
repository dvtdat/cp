// tinh buon khong phai luc' nao` cung chi? de quen di
// tinh buon luu giu bao nhieu mong mo luc' xuan thi`

#include <bits/stdc++.h>
#define inf INT_MAX
#define N 100010

using namespace std;

int a[4][N], f[4][N];

int main()
{
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[1][i] >> a[2][i] >> a[3][i];
    }

    f[1][0] = a[1][0];
    f[2][0] = a[2][0];
    f[3][0] = a[3][0];

    for (int i = 1; i < n; ++i)
    {
        f[1][i] = a[1][i] + max(f[2][i - 1], f[3][i - 1]);
        f[2][i] = a[2][i] + max(f[1][i - 1], f[3][i - 1]);
        f[3][i] = a[3][i] + max(f[2][i - 1], f[1][i - 1]);
    }

    n--;
    cout << max(f[1][n], max(f[2][n], f[3][n]));
}
