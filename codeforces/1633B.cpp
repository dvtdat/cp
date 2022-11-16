// ai muon nghe khong?

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
    string s; cin >> s;

    int cnt1 = 0, cnt0 = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '0') cnt0++; else cnt1++;
    }

    if (cnt0 == cnt1) cout << cnt1 - 1 << '\n';
    else cout << min(cnt0, cnt1) << '\n';
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

