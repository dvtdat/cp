#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    if (b >= 0)
    {
        cout << (a + b) * n << endl; return;
    }

    int m = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] != s[i + 1]) m++;
    }

    cout << a * n + b * (m / 2 + 1) << endl;
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
