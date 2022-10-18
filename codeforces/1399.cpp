// hong bik em dang lam gi z nhi?

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> cnt(n + 1);

    for (int i = 0; i < n; ++i)
    {
        int tmp; cin >> tmp;
        cnt[tmp]++;
    }


    int res = 0;
    for (int i = 2; i <= n * 2; ++i)
    {
        int tmp = 0;
        for (int j = 1; j < (i + 1) / 2; ++j)
        {
            if (i - j > n) continue;
            tmp += min(cnt[j], cnt[i - j]);
        }

        if (i % 2 == 0) tmp += cnt[i / 2] / 2;
        res = max(res, tmp);
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}
