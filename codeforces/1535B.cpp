//toi that bai

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);

    for (int& i : a) cin >> i;

    sort(a.begin(), a.end(), [](int x, int y) {
         return x % 2 < y % 2;});

    int cnt = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            cnt += (__gcd(a[i], a[j] * 2) > 1 ? 1 : 0);
        }
    }

    cout << cnt << endl;
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
