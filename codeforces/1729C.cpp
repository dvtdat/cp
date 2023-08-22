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
    string s; cin >> s;
    int n = s.length();

    vector<ii> a(n);

    for (int i = 0; i < n; ++i)
    {
        a[i] = ii((s[i] - 'a'), i);
    }

    int res = 0;
    int idx = 0; 
    vector<ii> b;

    if (s[0] >= s[n - 1])
    {
        for (int i = 0; i < n; ++i)
        {
            if (s[0] >= s[i] && s[i] >= s[n - 1]) b.push_back(a[i]);
        }
        for (int i = 0; i < b.size(); ++i) b[i].second = -b[i].second;
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < b.size(); ++i) b[i].second = -b[i].second;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (s[n - 1] >= s[i] && s[i] >= s[0]) b.push_back(a[i]);
        }
        sort(b.begin() + 1, b.end());
    }

    for (int i = 0; i < b.size() - 1; ++i) res += abs(b[i].first - b[i + 1].first);

    cout << res << ' ' << b.size() << '\n';
    for (ii i : b) cout << i.second + 1 << ' '; cout << '\n';
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

