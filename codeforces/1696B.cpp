#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    int tmp, prev = 0, cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if (tmp == 0 && prev != 0) cnt++;
        prev = tmp;
    }

    if (prev != 0) cnt++;

    if (cnt == 0) cout << 0;
    else if (cnt == 1) cout << 1;
    else cout << 2;

    cout << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
