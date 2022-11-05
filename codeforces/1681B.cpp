// xac' o bach khoa, hon` o nhan van

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

    int m;
    ll cnt = 0;
    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        ll u; cin >> u; cnt += u;
    }

    cout << a[cnt % n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}

