#include <bits/stdc++.h>

using namespace std;

int cal(vector<int> &a, int n, int start, int dir)
{
    int rad = 1;
    int prev = start;

    while (true)
    {
        int next = prev;

        while (next + dir >= 0 && next + dir <= n && abs(a[next + dir] - a[prev]) <= rad)
            next += dir;

        if (next == prev) break;

        prev = next;
        rad++;
    }

    return (abs(prev - start));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n; cin >> n;
    vector<int> a(n);

    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = max(res, cal(a, n, i, 1) + cal(a, n, i, -1) + 1);
    }

    cout << res;
}
