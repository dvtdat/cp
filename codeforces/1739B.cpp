// tram kam

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void solve()
{
    int n; cin >> n;

    vector<long long> a(n), b(n);

    for (long long &i : a) cin >> i;
    for (long long &i : b) cin >> i;

    long long mx = 0, res = 0;
    for (long long &i : b) mx = max(mx, i);

    for (long long &i : a) res += i;
    for (long long &i : b) res += i;

    cout << res - mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}




