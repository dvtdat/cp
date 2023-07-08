// 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;
typedef pair<int, ii> iii;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n, m, k; cin >> n >> m >> k;

    vector<ii> a;

    for (int i = 0; i < n; ++i)
    {
        vector<ll> tmp(m);
        for (int j = 0; j < m; ++j) cin >> tmp[j];
        sort(tmp.begin(), tmp.end());

        ll pen = tmp[0];
        bool flag = true;

        if (tmp[0] > k)
        {
            a.push_back(ii(0, 0));
            continue;
        }

        for (int j = 1; j < m; ++j)
        {
            if (tmp[j] + tmp[j - 1] > k)
            {
                a.push_back(ii(-j, pen));
                flag = false;
                break;
            }
            tmp[j] += tmp[j - 1];
            pen += tmp[j];
        }
        if (flag) a.push_back(ii(-m, pen));
    }

    ii save = a[0];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == save)
        {
            cout << i + 1 << '\n';
            return;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//

