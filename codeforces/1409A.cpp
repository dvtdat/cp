#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;

    cout << (long long)ceil(1.0 * abs(a - b) / 10) << endl;
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
