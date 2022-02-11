//toi ngheo`

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    if (n & 1)
    {
        cout << 3 << ' ' << 1 << ' ' << 2 << ' ';
        for (int i = 4; i < n; i += 2) cout << i + 1 << ' ' << i << ' ';
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= n; i += 2) cout << i + 1 << ' ' << i << ' ';
        cout << endl;
    }
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
