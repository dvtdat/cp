// 1 hour of suffering D:

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;

    b = a;

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i]) res++;
    }

    cout << (res == 2 || res == 0 ? "YES" : "NO");

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}




