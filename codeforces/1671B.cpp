// chill dude
// my class suck
// my team suck
// everything suck

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

    vector<int> a(n);
    for (int &i : a) cin >> i;

    int mn = inf, mx = 0;

    for (int i = 0; i < n; ++i)
    {
        a[i] -= i;
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    cout << (mx - mn <= 2 ? "YES" : "NO");
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}


