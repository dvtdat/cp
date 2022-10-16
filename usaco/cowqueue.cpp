//lai khong cam xuc

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n; cin >> n;

    vector<ii> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }

    int cur = 0;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
    {
        if (cur <= v[i].first)
        {
            cur = v[i].first;
        }

        cur += v[i].second;
    }

    cout << cur;
}
