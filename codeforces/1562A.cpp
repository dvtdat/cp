#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int l, r; cin >> l >> r;

    if (r / 2 < l) cout << r % l << endl;
    else cout << r / 2 + (r & 1 ? 1 : 0) - 1 << endl;
}

int main()
{
    int test;
    cin >> test;
    while (test--) solve();
}
