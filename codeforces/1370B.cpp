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
    
    vector<int> even, odd;

    for (int i = 1; i <= n * 2; ++i)
    {
        int u; cin >> u;
        if (u & 1) odd.push_back(i);
        else even.push_back(i);
    }

    if (odd.size() & 1) odd.pop_back(), even.pop_back();
    else
    {
        if (odd.size() >= 2)
        {
            odd.pop_back();
            odd.pop_back();
        }
        else
        {
            even.pop_back();
            even.pop_back();
        }
    }

    for (int i = 0; i < odd.size(); i += 2) cout << odd[i] << ' ' << odd[i + 1] << '\n';
    for (int i = 0; i < even.size(); i += 2) cout << even[i] << ' ' << even[i + 1] << '\n';
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

