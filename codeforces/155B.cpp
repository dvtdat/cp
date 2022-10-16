// troi hom nay nhieu may cuc

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n; cin >> n;

    vector<ii> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].second >> a[i].first;
    }

    sort(a.rbegin(), a.rend());

    int res = 0, cnt = 1;

    for (int i = 0; i < n; ++i)
    {
        cnt--; cnt += a[i].first;
        res += a[i].second;

        if (cnt == 0) break;
    }

    cout << res;
}
