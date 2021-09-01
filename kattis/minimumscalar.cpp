#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long test, n;
    cin >> test;
    for (long long i = 1; i <= test; ++i)
    {
        cin >> n;
        vector<long long> a(n), b(n);

        for (long long i = 0; i < n; ++i) cin >> a[i];
        for (long long i = 0; i < n; ++i) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        long long res = 0;

        for (long long i = 0; i < n; ++i) res += a[i] * b[i];

        cout << "Case #" << i << ": ";
        cout << res << endl;
    }
}
