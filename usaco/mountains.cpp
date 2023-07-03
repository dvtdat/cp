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

bool cmp(const ii& a, const ii& b)
{
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

void solve()
{
    int n; cin >> n;
    vector<ii> coor(n);

    for (int i = 0; i < n; ++i)
    {
        int x, y; cin >> x >> y;
        coor[i].first = x - y;
        coor[i].second = x + y;
    }

    sort(coor.begin(), coor.end(), cmp);

    int cnt = 0;
    int right = coor[0].second;

    for (int i = 1; i < n; ++i)
    {
        if (coor[i].second <= right) cnt++;
        else right = coor[i].second;
    }

    cout << n - cnt << '\n';
}

int main()
{
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
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

