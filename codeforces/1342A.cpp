#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long x, y, a, b; cin >> x >> y >> a >> b;

    if (y > x) swap(x, y);

    if (a * 2 <= b) cout << (x + y) * a << '\n';
    else cout << y * b + (x - y) * a << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
