#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int t; cin >> t;
        sum += t;
    }
    if (sum >= n) cout << sum - n << endl;
    else cout << 1 << endl;
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
