#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x;
    vector<int> a(3);

    cin >> x;
    cin >> a[0] >> a[1] >> a[2];

    if (a[0] == 1 || a[1] == 2 || a[2] == 3 || a[x - 1] == 0)
    {
        cout << "NO\n";
    }
    else cout << "YES\n";
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
