#include <bits/stdc++.h>
#define maxN 1010

using namespace std;

typedef pair<int, int> ii;

int a[maxN][maxN];
bool mark[maxN][maxN];
int n, m;

int td[4] = {1, -1, 0, 0};
int tc[4] = {0, 0, 1, -1};

bool check(int x, int y)
{
    return (x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1);
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            char c; cin >> c;
            a[i][j] = (int)(c - '0');
        }
    }

    int cnt = 0;

    queue<ii> q;
    q.push(ii(0, 0));

    for (int i = 0; i < maxN; ++i)
        for (int j = 0; j < maxN; ++j) mark[i][j] = false;

    while (!q.empty())
    {
        ii u = q.front(); q.pop();

        if (mark[u.first][u.second]) continue;
        mark[u.first][u.second] = true;

        for (int k = 0; k < 4; ++k)
        {
            int x = u.first + td[k];
            int y = u.second + tc[k];

            if (check(x, y))
            {
                if (a[x][y]) cnt++;
                else q.push(ii(x, y));
            }
        }
    }

    cout << cnt;
}
