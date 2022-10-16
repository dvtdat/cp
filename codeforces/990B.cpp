// ussh <3

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    vector<ii> b;

    b.push_back(ii(a[0], 1));

    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1]) b.push_back(ii(a[i], 1));
        else b[b.size() - 1].second++;
    }

    int res = n;
    for (int i = 1; i < b.size(); ++i)
    {
        //cout << b[i].first << ' ' << b[i].second << '\n';
        if (b[i].first - b[i - 1].first <= k) res -= b[i - 1].second;
    }

    cout << res;
}
