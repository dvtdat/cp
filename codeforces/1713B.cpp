#include <bits/stdc++.h>

using namespace std;

int a[100010];

void solve()
{
    int n; cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    int pre = 1, suf = 1;

    while (a[pre] <= a[pre + 1] && pre < n) pre++;
    while (a[n - suf] >= a[n - suf + 1] && suf < n) suf++;

    if (pre + suf >= n) cout << "yes\n"; else cout << "no\n";
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
