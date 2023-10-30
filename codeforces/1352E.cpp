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
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);

    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 0; i < n - 1; ++i)
    {   
        int tmp = a[i];
        for (int j = i + 1; j < n; ++j)
        {
            tmp += a[j];
            if (tmp > n) break;
            res += cnt[tmp];
            cnt[tmp] = 0;
        }
    }

    cout << res << '\n';
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

