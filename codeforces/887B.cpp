// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(6, -1));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 6; ++j) cin >> v[i][j];
    }

    for (int i = 1; i <= 99; ++i)
    {
        int a = i % 10;
        int b = i / 10;
        bool flag = false;

        if (b == 0)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (find(v[j].begin(), v[j].end(), a) != v[j].end()) flag = true;
            }
        }
        else if (n >= 2)
        {
            for (int j = 0; j < 3; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    if (j == k) continue;
                    if (find(v[j].begin(), v[j].end(), a) != v[j].end() && find(v[k].begin(), v[k].end(), b) != v[k].end()) flag = true;
                }
            }
        }

        if (!flag)
        {
            cout << i - 1 << '\n';
            return;
        }
    }
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("text");
    int test = 1; //cin >> test;
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

