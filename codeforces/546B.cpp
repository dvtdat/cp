// ngta dang doi. m day'

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);

    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] <= a[i - 1])
        {
            res += a[i - 1] - a[i] + 1;
            a[i] = a[i - 1] + 1;
        }
    }

    cout << res;
}
