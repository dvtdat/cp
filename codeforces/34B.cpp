#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    vector<int> a(n);

    int res = 0;
    for (int &i : a) cin >> i;

    sort (a.begin(), a.end());

    for (int i = 0; i < m; ++i) res += a[i] < 0 ? a[i] : 0;

    cout << -res;
}
