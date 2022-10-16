//khong cam xuc

#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    n *= 2;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int res = inf;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            vector<int> v;
            for (int k = 0; k < n; ++k)
            {
                if (k != i && k != j) v.push_back(a[k]);
            }

            int tmp = 0;
            for (int k = 1; k < v.size(); k += 2)
            {
                tmp += v[k] - v[k - 1];
            }

            res = min(res, tmp);
        }
    }

    cout << res;
}
