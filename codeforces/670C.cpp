// lan dau dc hien mau' :yay:

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
    int n, m; cin >> n;

    map<int, int> a;

    for (int i = 0; i < n; ++i)
    {
        int tmp; cin >> tmp;
        if (!a.count(tmp)) a.insert({tmp, 1});
        else a[tmp]++;
    }

    cin >> m;
    vector<ii> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i].first;
    for (int i = 0; i < m; ++i) cin >> b[i].second;

    int mx1 = 0, mx2 = 0, ans = 0;
    for (int i = 0; i < m; ++i)
    {
        if (mx1 < a[b[i].first] || (mx1 == a[b[i].first] && mx2 < a[b[i].second]))
        {
            ans = i;
            mx1 = a[b[i].first];
            mx2 = a[b[i].second];
        }
    }

    cout << ans + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}

