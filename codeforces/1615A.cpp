//toi that bai

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    int tmp, s = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp; s += tmp;
    }

    if (s % n == 0) cout << 0;
    else cout << 1; cout << endl;
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}

