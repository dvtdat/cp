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
    vector<int> b(n);

    for (int &i : a) cin >> i;
    
    int mx = *max_element(a.begin(), a.end());

    for (int &i : a)
    {
        if (mx != i) continue;
        b[0] = i;
        i = 0;
        break;
    }

    for (int i = 1; i < n; ++i)
    {
        int idx = 0, mxGCD = 0;
        for (int j = 0; j < n; ++j)
        {
            if (!a[j] || __gcd(a[j], mx) <= mxGCD) continue;
            mxGCD = __gcd(a[j], mx);
            idx = j;
        }

        b[i] = a[idx];
        mx = mxGCD;
        a[idx] = 0;
    }

    for (int i : b) cout << i << ' '; cout << '\n';
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

