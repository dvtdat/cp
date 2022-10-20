// van doi' bung. (va` nho' em)

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void solve()
{
    int n; cin >> n;

    vector<ii> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    int mx = a[0].second;

    for (int i = 1; i < n; ++i)
    {
        if (mx <= a[i].second) mx = a[i].second;
        else mx = a[i].first;
    }

    cout << mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}


