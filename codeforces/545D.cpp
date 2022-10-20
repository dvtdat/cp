// vl suffer the nay den biet bao gio

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> a(n);

    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    int res = 0, tmp = 0, i = 0;
    while (i < n)
    {
        if (a[i] >= tmp) res++, tmp += a[i];
        i++;
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
