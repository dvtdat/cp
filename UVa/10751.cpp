#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test; cin >> test;
    while (test--)
    {
        int n; cin >> n;
        double res = (n - 1) * 4;
        if (n >= 3) res = res + ((n - 2) * (n - 2) * sqrt(2));

        cout << fixed << setprecision(3) << res << '\n';
        if (test != 0) cout << '\n';
    }

    return 0;
}