//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    string sx= "";
    int res = 0, cnt = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (s[i] == s[j] && s[i + 1] == s[j + 1]) cnt++;
        }

        if (cnt > res)
        {
            res = cnt;
            sx = string(1, s[i]) + string(1, s[i + 1]);
        }

        cnt = 0;
    }

    cout << sx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|

