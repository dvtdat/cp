#include <bits/stdc++.h>

using namespace std;


int a[] = {10, 45, 150, 375,
        750, 1200, 1713, 2227,
        2492, 2492, 2225, 2041,
        1575, 1132, 770, 571,
        335, 180, 90, 44,
        18, 12, 6, 3, 1,
        0, 0};

int main()
{
    int n; cin >> n;
    if (n > 25) cout << 0;
    else cout << a[n - 1];
}
