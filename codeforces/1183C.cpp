// A2 khong hoat dong den t6 :(

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int inf = 1e9 + 7;

void solve()
{
    long long k, n, a, b; cin >> k >> n >> a >> b;

    long long l = 0, r = n, mid, res = -1;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (mid * a + (n - mid) * b < k)
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res << '\n';

}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}

