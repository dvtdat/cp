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

int num[maxN];
char s[100];

void solve()
{
    int cnt = 0;
    
    cin >> s;

    int n = 1;
    while (s[n]) n++;

    for (int i = 0; i <= n - 3; i += 2)
    {
        num[cnt++] = s[i] - '0';
    }
    num[cnt++] = s[n - 1] - '0';
    sort(num, num + cnt);

    for (int i = 0; i < cnt - 1; ++i) cout << num[i] << '+';
    cout << num[cnt - 1];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
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

