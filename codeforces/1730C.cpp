// ut x ussh, never happen

#include <bits/stdc++.h>

using namespace std;

const int inf = 2e5 + 100;

void solve()
{
    string s; cin >> s;

    int n = s.size();
    vector<int> a(n), cnt(10), mn(n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = s[i] - '0';
        cnt[s[i] - '0']++;
    }

    int tmp = inf;
    for (int i = n - 1; i >= 0; --i)
    {
        tmp = min(tmp, a[i]);
        mn[i] = tmp;
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] != mn[i])
        {
            cnt[a[i]]--;
            cnt[min(a[i] + 1, 9)]++;
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < cnt[i]; ++j) cout << i;
    }

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}

