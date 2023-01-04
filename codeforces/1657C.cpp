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

    int i = 0;
    int cntOp = 0, cntChar = 0, remain = n;

    while (i < n)
    {
        if (s[i] == '(' && i != n - 1)
        {
            cntOp++;
            remain -= 2;
            i += 2;
        }
        else
        {
            i++; cntChar = 1;

            while (s[i] == '(' && i < n)
            {
                cntChar++;
                i++;
            }

            if (s[i] == ')' && i < n)
            {
                cntOp++;
                remain -= cntChar + 1;
            }
            i++;
        }
    }

    cout << cntOp << ' ' << remain << '\n';
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

