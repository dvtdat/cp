// vi sao em phai khoc

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

    vector<int> a(30);

    for (int i = 0; i < s.size(); ++i)
    {
        a[s[i] - 'a']++;
    }

    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != 0 && a[i] % n != 0)
        {
            cout << -1; return;
        }
    }

    string res;

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i] / n; ++j)
        {
            res += i + 'a';
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << res;
    }

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
//
//
