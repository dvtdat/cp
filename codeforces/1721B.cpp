//lmao bfs

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;

    if ((sy - d <= 1 || sx + d >= n) && (sy + d >= m || sx - d <= 1)) cout << -1;
    else cout << n + m - 2;

    cout << '\n';

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}

