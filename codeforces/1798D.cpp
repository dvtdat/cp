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
    vector<int> a, b, v;

    for (int i = 0; i < n; ++i)
    {
        int u; cin >> u;
        if (u < 0) a.push_back(u); else b.push_back(u);
        v.push_back(u);
    }

    int A = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());

    if (A == 0)
    {
        cout << "NO\n"; return;
    }

    vector<int> res;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int cnt = 0;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        // cout << i << ' ' << j << '\n';
        while (cnt >= 0 && i < a.size())
        {
            cnt += a[i];
            res.push_back(a[i]);
            i++;
        }
        
        while (cnt < 0 && j < b.size())
        {
            cnt += b[j];
            res.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) res.push_back(a[i++]);
    while (j < b.size()) res.push_back(b[j++]);
    
    cout << "YES\n";
    for (int i : res) cout << i << ' '; cout << '\n';
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

