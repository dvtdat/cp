#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    long long res = 0;
    while (n--)
    {
        char c; cin >> c;
        if (c == 'O') res += 1LL << n;
    }

    cout << res;
}
