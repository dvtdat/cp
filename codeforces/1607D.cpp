// coffee is ok, i guess

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> tmp(n), a, b;

    for (int &i : tmp) cin >> i;

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        if (c == 'B') a.push_back(tmp[i]);
        else b.push_back(tmp[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int cnt = 1;

    for (int i : a)
    {
        if (i < cnt)
        {
            cout << "NO\n"; return;
        }
        cnt++;
    }

    for (int i : b)
    {
        if (i > cnt)
        {
            cout << "NO\n"; return;
        }
        cnt++;
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}
