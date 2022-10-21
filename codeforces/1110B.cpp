// 6PM at A2

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int sum = k;
    for (int i = 0; i < n - 1; ++i)
    {
        b[i] = a[i + 1] - a[i];
        sum += b[i];
    }

    sort(b.rbegin(), b.rend());

    for (int i = 0; i < k - 1; ++i)
    {
        sum -= b[i];
    }

    cout << sum;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}
