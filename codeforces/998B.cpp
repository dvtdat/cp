// chuyen xe buyt 08

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k; cin >> n >> k;

    vector<int> a(n + 1), p(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = a[i] % 2 == 0 ? 1 : -1;
    }

    p[1] = b[1];
    for (int i = 2; i <= n; ++i) p[i] = p[i - 1] + b[i];


    vector<int> dis;
    for (int i = 1; i < n; ++i)
    {
        if (p[i] == 0) dis.push_back(abs(a[i + 1] - a[i]));
    }

    sort(dis.begin(), dis.end());

    int res = 0, cnt = 0;

    for (int i = 0; i < dis.size(); ++i)
    {
        if (res + dis[i] > k)
        {
            cout << cnt;
            return;
        }
        res += dis[i];
        cnt++;
    }

    cout << cnt;
}

int main()
{
    //int test = 1; //cin >> test;
    //while (test--)

    solve();
}


