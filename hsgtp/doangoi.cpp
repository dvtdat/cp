// tat ca nhung thu may thay la lam, cuoc doi tao nhu la cho tha, su that

#include <bits/stdc++.h>
#define N 1010
#define inf INT_MAX

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

iii p[N];
int f[N];

int main()
{
    freopen("DOANGOI.INP", "r", stdin);
    freopen("DOANGOI.OUT", "w", stdout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].first.second >> p[i].first.first;
        p[i].second = i;
    }

    sort(p, p + n);

    f[0] = p[0].first.first - p[0].first.second;
    for (int i = 1; i < n; ++i)
    {
        f[i] = p[i].first.first - p[i].first.second;
        for (int j = 0; j < i; ++j)
        {
            if (p[i].first.second == p[j].first.first)
            {
                f[i] = max(f[i], f[j] + p[i].first.first - p[i].first.second);
            }
        }
    }

    int res = 0, tmp = 0;
    for (int i = 0;i < n; ++i)
    {
        if (f[i] > res)
        {
            res = f[i];
            tmp = i;
        }
    }

    cout << res << endl;

    vector<int> a;
    vector<iii> b;

    while (res != 0)
    {
        int tmp1 = tmp;
        a.push_back(tmp);
        res -= p[tmp].first.first - p[tmp].first.second;
        for (int i = 0; i < tmp1; ++i) if (res == f[i]) tmp = i;
    }

    for (int i : a) b.push_back(iii(ii(p[i].first.second, p[i].first.first), p[i].second));

    sort(b.begin(), b.end());
    for (iii i : b) cout << i.second + 1 << endl;

}
