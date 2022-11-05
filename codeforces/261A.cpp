// nong' nhu cai' lo`

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
    int m; cin >> m;
    vector<int> a(m);
    for (int &i : a) cin >> i;

    int n; cin >> n;
    vector<int> b(n);
    for (int &i : b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());


    int i = 0, j = 0;
    ll sum = 0;

    while (i < n)
    {
        j = 0;
        while (j < a[0] && i < n) sum += 1LL * b[i++], j++;
        j = 0;
        while (j < 2 && i < n) i++, j++;
    }

    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}



