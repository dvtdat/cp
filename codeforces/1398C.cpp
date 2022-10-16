#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> p(n + 5, 0);

    for (int i = 1; i <= n; ++i)
    {
        char c; cin >> c;
        p[i] = c - '0';
    }

    for(int i = 1; i <= n; ++i) p[i] += p[i - 1];

    map<int, long long> m;
    for(int i = 0; i <= n; ++i)
    {
        m[i - p[i]]++;
    }

    long long res = 0;
    for (auto i : m)
    {
        long long x = i.second;
        res += x * (x - 1) / 2;
    }

    cout << res << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
