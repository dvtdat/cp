// mot nha tu hinh trai tym

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

int res = inf;
bool flag = false;
string s;

void gen(int n, vector<bool> bit, int i)
{
    if (i == n)
    {
        int k = 1;
        int cnt = 0, tmp = 0, last = -1;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (!bit[i]) continue;
            tmp += (s[i] - '0') * k;
            k *= 10;
            cnt++;
            last = (s[i] - '0');
        }
        if (sqrt(1.0 * tmp) == 1.0 * (int)sqrt(tmp) && tmp != 0 && last != 0) res = min(res, n - cnt), flag = true;
        // cout << tmp << ' ' << cnt << ' ' << res << '\n';
        return;
    }

    bit[i] = 0;
    gen(n, bit, i + 1);

    bit[i] = 1;
    gen(n, bit, i + 1);
}

void solve()
{
    cin >> s;
    vector<bool> bit(s.length());

    gen(s.length(), bit, 0);

    cout << (flag ? res : -1) << '\n';
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

