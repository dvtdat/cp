// khong cam xuc

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n; cin >> n;

    vector<ii> a(n);

    int mn = INT_MAX, mx = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        mn = min(mn, a[i].first);
        mx = max(mx, a[i].second);
    }


    for (int i = 0; i < n; ++i)
    {
        if (a[i].first == mn && a[i].second == mx)
        {
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;
}
