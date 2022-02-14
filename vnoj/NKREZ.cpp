//les misérable

#include <bits/stdc++.h>
#define N 10100

using namespace std;

typedef pair<int, int> ii;

ii a[N];
int f[N];

int main()
{
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].second >> a[i].first;
    }

    sort(a, a + n);

    f[0] = a[0].first - a[0].second;
    for (int i = 1; i < n; ++i)
    {
        f[i] = a[i].first - a[i].second;
        for (int j = 0; j < i; ++j)
        {
            if (a[i].second >= a[j].first)
            {
                f[i] = max(f[i], f[j] + a[i].first - a[i].second);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = max(res, f[i]);
    }

    cout << res;
}
