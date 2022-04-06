//ah shit here we go again

#include <bits/stdc++.h>
#define N 110
#define inf INT_MAX

using namespace std;

typedef pair<int, int> ii;

int a[N][N], d[N][N];
int n, m;
int td[4] = {0, 0, -1 ,1},
    tc[4] = {1, -1, 0, 0};

bool check(int x, int y)
{
    return (x < n && x >= 0 && y < m && y >= 0);
}

void bfs(int x, int y)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) d[i][j] = inf;
    d[x][y] = 0;

    queue<ii> q;
    q.push(ii(x, y));

    while (!q.empty())
    {
        int ui = q.front().first;
        int uj = q.front().second;
        q.pop();


        for (int k = 0; k < 4; ++k)
        {
            int vi = ui + td[k];
            int vj = uj + tc[k];

            if (check(vi, vj) && a[vi][vj] == 0 && d[vi][vj] == inf)
            {
                q.push(ii(vi, vj));
                d[vi][vj] = d[ui][uj] + 1;
            }
        }
    }

}

int main()
{
    cin >> n >> m;

    int si, sj, ti, tj;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char tmp; cin >> tmp;
            if (tmp == '.') a[i][j] = 0;
            else if (tmp == '*') a[i][j] = 1;
            else if (tmp == 'B') si = i, sj = j, a[i][j] = 0;
            else if (tmp == 'C') ti = i, tj = j, a[i][j] = 0;
        }
    }

    bfs(si, sj);

    cout << d[ti][tj];
}
