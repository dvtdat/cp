// you just want attention, you dont want my heart

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    vector<int> a(3);

    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    if (a[0] == a[2] - 2)
    {
        cout << 0 << '\n';
    }
    else if (a[1] == a[2] - 2 || a[0] == a[1] - 2)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 2 << '\n';
    }

    cout << max(a[2] - a[1], a[1] - a[0]) - 1;
}
