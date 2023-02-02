// 

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

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

int home[maxN], away[maxN];
int homeTime[maxN], awayTime[maxN];
string homeStr, awayStr;

void solve()
{  
    memset(home, 0, sizeof home);
    memset(away, 0, sizeof away);
    memset(homeTime, 91, sizeof homeTime);
    memset(awayTime, 91, sizeof awayTime);

    cin >> homeStr >> awayStr;
    int n; cin >> n;

    vector<pair<ii, string>> res;

    for (int i = 0; i < n; ++i)
    {
        int t, num; char team, card;
        cin >> t >> team >> num >> card;

        if (team == 'h')
        {
            if (card == 'y') home[num]++;
            if (card == 'r' || home[num] == 2) homeTime[num] = min(homeTime[num], t);
        }
        else
        {
            if (card == 'y') away[num]++;
            if (card == 'r' || away[num] == 2) awayTime[num] = min(awayTime[num], t);
        }
    }

    for (int i = 0; i <= 100; i++)
    {
        if (homeTime[i] < 91) res.push_back({ii(homeTime[i], i), homeStr});
        if (awayTime[i] < 91) res.push_back({ii(awayTime[i], i), awayStr});
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i].second << ' ' << res[i].first.second << ' ' << res[i].first.first << '\n';
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

