// idk what the future will be (?) life definitely is a lot more complicated that what i would have thought
// for whatever reason i will record this memory here
// for future me: i will left this as a confusion, if you dont remember it, good to you and good that you will never remember it
// tbh, as i writing this, it might left a pernament scar in me that i might never forget, fck me

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

void solve()
{
    int n, q; cin >> n >> q;

    vector<int> a(n);
    vector<int> l(n, 0), r(n, -1);

    for (int &i : a) cin >> i;

    int tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < tmp) l[i] = 1;
        else
        {
            l[i] = 0;
            tmp = a[i];
        }
    }

    for (int i = 0, j = 0; i < n && j < n;)
    {
        if (a[j] > a[i])
        {
            r[i] = j;
            i = j;
        }
        j++;
    }

    int i, k;
    while (q--)
    {
        cin >> i >> k; i--;
        if (l[i]) cout << 0 << '\n';
        else if (a[i] == n) cout << max(k - i + (i ? 1 : 0), 0) << '\n';
        else cout << max(0, min(k - i + (i ? 1 : 0), r[i] - i - (i ? 0 : 1))) << '\n';
    }

    // for (int i = 0; i < n; ++i) cout << l[i] << ' '; cout << '\n';
    // for (int i = 0; i < n; ++i) cout << r[i] << ' '; cout << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
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

