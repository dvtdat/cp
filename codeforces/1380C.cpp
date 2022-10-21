// 1 hour of suffering D:

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<long long> a(n);

    long long mx = 0, sum = 0;
    for (long long &i : a)
    {
        cin >> i;
        mx = max(mx, i);
        sum += i;
    }

    long long k = max(mx, (sum + n - 2) / (n - 1));
    cout << k * (n - 1) - sum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}




