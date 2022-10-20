// rang' len nao ngta dang cho` m day'

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> a(n), b(n), c(n), p(n);

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    for (int &i : a) i--;
    for (int &i : b) i--;

    for (int i = 0; i < n; ++i)
    {
        p[b[i]] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        c[i] = p[a[i]];
    }

    int mx = -INT_MAX, res = 0;

    for (int i = 0; i < n; ++i)
    {
        if (c[i] > mx) mx = c[i];
        else res++;
    }


    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}
