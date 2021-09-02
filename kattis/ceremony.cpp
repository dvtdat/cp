#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int res = n;
    for (int i = 1; i <= n; ++i)
    {
        res = min(res, a[i] + n - i);
    }

    cout << res;
}
