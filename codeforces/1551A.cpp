#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    cout << 1LL * n / 3 + (n % 3 == 1 ? 1 : 0) << ' ' << 1LL * n / 3 + (n % 3 == 2 ? 1 : 0) << endl;
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
