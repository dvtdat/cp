//nong'

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> a(n), ok(n);

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        ok[i] = c == '0' ? 0 : 1;
    }

    for (int &i : a) cin >> i;


    int j = -1;

    for (int i = 0; i < n; ++i)
    {
        if (!ok[i])
        {
            j = i;
        }
        else if (j >= 0 && a[i] < a[j])
        {
            swap(ok[i], ok[j]);
            j = i;
        }
    }

    long long res = 0;

    for (int i = 0; i < n; ++i)
    {
        if (ok[i]) res += a[i];
    }

    //for (int i = 0; i < n; ++i) cout << ok[i];

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}


