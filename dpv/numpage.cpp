#include <bits/stdc++.h>

using namespace std;

int a[10010];

int main()
{
    freopen("numpage.inp", "r", stdin);
    freopen("numpage.out", "w", stdout);

    int n; cin >> n;

    memset(a, 0, sizeof a);

    a[4] = 1;
    a[10] = 1;
    a[100] = 1;
    a[1000] = 1;
    a[10000] = 1;

    for (int i = 5; i < 10010; i++)
    {
        a[i] += a[i - 1];
    }

    int res = 4;
    for(; n; res++) n -= a[res];

    cout << res - 1;
}
