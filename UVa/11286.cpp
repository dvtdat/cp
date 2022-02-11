//toi chi muon duoc hanh. phuc' thoi

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        map<vector<int>, int> _map;
        map<vector<int>, int>::iterator it;
        vector<int> a(5);
        int cnt = 0;

        for (int k  = 0; k < n; ++k)
        {
            for (int i = 0; i < 5; ++i) cin >> a[i];
            sort(a.begin(), a.end());

            if (_map.count(a) == 1) _map[a]++; else _map[a] = 1;
        }
        int mx = 0;
        for (it = _map.begin(); it != _map.end(); it++) mx = max(mx, it -> second);
        for (it = _map.begin(); it != _map.end(); it++) if (it -> second == mx) cnt++;

        cout << cnt * mx << '\n';
    }
}

