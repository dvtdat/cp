// mua them ao' khong nhi?, 110k?

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, r; cin >> n >> r;

    vector<int> a(n);

    for (int &i : a)
    {
        cin >> i;
        //i = i / r + (i % r ? 1 : 0);
    }

    sort(a.rbegin(), a.rend());

    vector<int> b;
    b.push_back(0);

    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != a[i - 1]) b.push_back(a[i]);
    }

    int res = 0;
    for (int i : b)
    {
        res += (i > res * r);
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}


