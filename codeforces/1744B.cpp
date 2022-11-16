// vl khong the tin dc

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
    int n, q; cin >> n >> q;

    ll sum = 0;
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i)
    {
        int t; cin >> t;
        sum += t;
        if (t % 2) odd++; else even++;
    }

    while (q--)
    {
        int type, num; cin >> type >> num;

        if (type)
        {
            sum += odd * num;
            if (num % 2)
            {
                even += odd;
                odd = 0;
            }
        }
        else
        {
            sum += even * num;
            if (num % 2)
            {
                odd += even;
                even = 0;
            }
        }

        cout << sum << '\n';
    }
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

