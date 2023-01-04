// lmao O(n)

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

int a[10010];

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    s += ' ';

    memset(a, -1, sizeof a);

    for (int i = 0; i < n; ++i)
    {
        int val = (s[i] - '0') * 100 + (s[i + 1] - '0');
        if (a[val] == -1)
        {
            a[val] = i;
        }
        else if (a[val] < i - 1)
        {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

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

