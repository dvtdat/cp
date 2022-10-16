#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX;

int main()
{
    int n; cin >> n;

    int cur = 0;

    int u, v; cin >> u >> v;
    cur = max(u, v);

    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;

        if (cur >= max(u <= cur ? u : 0, v <= cur ? v : 0)) cur = max(u <= cur ? u : 0, v <= cur ? v : 0);

        if (cur == 0)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
