#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;

    vector<long long> a(n + 1), p(n + 1), ps(n + 1);

    for (int i = 1; i <= n; ++i) cin >> a[i];

    p[1] = a[1];
    for (int i = 2; i <= n; ++i) p[i] = a[i] + p[i - 1];

    map<long long, int> m;
    long long cnt = 0;

    m[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        cnt += m[p[i] - k];
        m[p[i]]++;
    }

    cout << cnt;
}
