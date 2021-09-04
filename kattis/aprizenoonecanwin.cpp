#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int& i : a) cin >> i;

    sort(a.begin(), a.end());

    int cnt = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] + a[i - 1] <= k) cnt++;
    }

    cout << cnt;
}
