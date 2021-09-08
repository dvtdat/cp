#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

bool cmp(ii l, ii r)
{
    if(l.second == r.second) return l.first < r.first;
    return l.second < r.second;
}

int main()
{
    int n; cin >> n;

    vector<ii> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), cmp);

    int cnt = 1;
    int now = a[0].second;

    for (int i = 1; i < n; ++i)
    {
        if (a[i].first > now)
        {
            now = a[i].second;
            cnt++;
        }
    }

    cout << cnt;
}
