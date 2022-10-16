//tinh yeu ma, trong vui ve nhi?

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int s, n; cin >> s >> n;

    vector<ii> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i)
    {
        if (s > a[i].first)
        {
            s += a[i].second;
            continue;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
