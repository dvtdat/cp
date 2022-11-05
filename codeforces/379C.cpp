// bung. doi' con` cao`

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
    vector<ii> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    int cur = 0;

    for (int i = 0; i < n; ++i)
    {
        if (cur >= a[i].first) a[i].first = ++cur;
        else cur = a[i].first;

        b[a[i].second] = a[i].first;
    }

    for (int i : b) cout << i << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}
