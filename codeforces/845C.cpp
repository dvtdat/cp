// final fairwell, great granddad!

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

vector<int> indicies;

int compress(int x)
{
    return lower_bound(indicies.begin(), indicies.end(), x) - indicies.begin();
}

void solve()
{
    int n; cin >> n;
    vector<ii> b(n);
    vector<int> pre(maxN * 2);
    

    for (int i = 0; i < n; ++i)
    {
        cin >> b[i].first >> b[i].second;
        indicies.push_back(b[i].first);
        indicies.push_back(b[i].second);
    }

    sort(indicies.begin(), indicies.end());
    indicies.erase(unique(indicies.begin(), indicies.end()), indicies.end());

    for (int i = 0; i < n; ++i)
    {
        pre[compress(b[i].first)] += 1;
        pre[compress(b[i].second) + 1] -= 1;
    }

    for (int i = 1; i < pre.size(); ++i)
    {
        pre[i] += pre[i - 1];
    }

    sort(pre.rbegin(), pre.rend());

    if (pre[0] > 2) cout << "NO\n";
    else cout << "YES\n";
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

