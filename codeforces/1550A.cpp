#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    int i = 1, cnt = 1, sum = 1;
    while (sum < n)
    {
        i += 2;
        sum += i;
        cnt++;
    }

    cout << cnt << endl;
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
