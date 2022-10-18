#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    cout << 1 << ' ';

    for (int i = n; i > 1; --i) cout << i << ' ';

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}

