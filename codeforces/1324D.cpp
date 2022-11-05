// lofi child in A5 from 8 to 6

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
    for (int i = 0; i < n; ++i) cin >> a[i];

    int tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp; a[i] -= tmp;
    }

    sort(a.begin(), a.end());

    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] <= 0) continue;

        int j = lower_bound(a.begin(), a.end(), -a[i] + 1) - a.begin();

        res += i - j;
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}
