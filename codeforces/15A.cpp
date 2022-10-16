#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n, t; cin >> n >> t;

    t *= 2;

    vector<ii> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        a[i].first *= 2;
        a[i].second *= 2;
    }

    sort(a.begin(), a.end());

    int res = 2;

    for (int i = 1; i < n; ++i)
    {
        int tmp = (a[i].first - a[i].second / 2) - (a[i - 1].first + a[i - 1].second / 2);
        if (tmp == t) res += 1;
        else if (tmp > t) res += 2;
    }

    cout << res;
}
