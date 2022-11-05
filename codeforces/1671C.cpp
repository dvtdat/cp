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
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    vector<long long> p(n);

    p[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        p[i] = p[i - 1] + a[i];
    }

    long long res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (k - p[i] >= 0) res += (k - p[i]) / (i + 1) + 1;
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}



