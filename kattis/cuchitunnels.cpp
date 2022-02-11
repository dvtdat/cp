#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> a(n);
    for (int& i : a) cin >> i;

    int sum = 0;
    for (int i = 1; i < n; ++i)
    {
        a[i]--;
        sum += a[i];
    }

    if (sum + a[0] != n - 1)
    {
        cout << "NO"; return 0;
    }

    int cnt = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] > cnt)
        {
            cout << "NO"; return 0;
        }
        cnt = cnt + 1 - a[i];
    }

    cout << "YES";
}
