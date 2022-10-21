// vibing in 402C4

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k; cin >> n >> k;

    vector<int> a(n), b(k);

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int cnt = 0;
    for (int &i : b) if (i == 1) cnt++;

    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    long long res = 0;

    for (int i = 0; i < k; ++i) res += a[i];
    for (int i = 0; i < cnt; ++i) res += a[i];

    int j = k, i = 0;

    while (j < n && i < k)
    {
        if (b[i] != 1)
        {
            res += a[j + b[i] - 2];
            j += b[i] - 1;
        }
        i++;
    }

    cout << res << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}

