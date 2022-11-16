// teo teo teo teo teo`

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

    int cnt = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; ++i)
    {
        int t; cin >> t;
        while (t % 2 == 0 && t) cnt++, t /= 2;
    }

    if (cnt >= n)
    {
        cout << 0 << '\n'; return;
    }

    vector<int> res;

    for (int i = n; i >= 1; --i)
    {
        cnt2 = 0;
        int ii = i;
        if (ii % 2 == 0) cnt3++;
        while (ii % 2 == 0 && ii)
        {
            cnt2++, ii /= 2;
        }
        res.push_back(cnt2);
    }

    sort(res.rbegin(), res.rend());

    for (int i = 0; i < res.size(); ++i)
    {
        if (res[i] + cnt >= n)
        {
            cout << i + 1 << '\n';
            return;
        }

        cnt += res[i];
    }

    cout << -1 << '\n'; return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

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

