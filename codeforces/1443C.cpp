// 65 nen mik bi sut' khoi? thu vien trong 2 ngay D:

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int inf = 1e9 + 7;

void solve()
{
    int n; cin >> n;

    vector<int> a(n), b(n);

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    long long sum, l = 0, r = inf, mid, res = 0;

    while (l <= r)
    {
        mid = (l + r) / 2;
        sum = 0;

        for (int i = 0; i < n; ++i)
        {
            if (a[i] > mid) sum += b[i];
        }

        if (sum <= mid)
        {
            res = mid, r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
