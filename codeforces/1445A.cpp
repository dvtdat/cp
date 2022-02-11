#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);

    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    for (int i = 0; i < n; ++i)
    {
        if (a[i] + b[i] > k)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
