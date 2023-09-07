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

int calc(int x)
{
    if (x <= 9) return 1;
    return (int)(1.0 * ceil(log10f(x + 1)));
}

void solve()
{
    int n; cin >> n;
    priority_queue<int> a, b;

    for (int i = 0; i < n; ++i)
    {
        int u; cin >> u;
        a.push(u);
    }
    
    for (int i = 0; i < n; ++i)
    {
        int u; cin >> u;
        b.push(u);
    }

    int res = 0;
    while (a.size())
    {
        if (a.top() == b.top())
        {
            a.pop(); b.pop();
            continue;
        }

        res++;
        if (a.top() > b.top())
        {
            a.push(calc(a.top()));
            a.pop();
        }
        else
        {
            b.push(calc(b.top()));
            b.pop();
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

