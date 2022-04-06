// neu mot mai toi bay len troi

#include <bits/stdc++.h>
#define N 1000
#define inf INT_MAX

using namespace std;

typedef pair<int, int> ii;

int a[N][N];
int td[8] = {-1, -1, -1, 0, 0, 1, 1, 1},
    tc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int mark[N][N];
int n, m;
bool flag;

bool check(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void bfs1(int i, int j)
{
    queue<ii> q; q.push(ii(i, j));
    mark[i][j] = true;

    while (!q.empty())
    {
        int ui = q.front().first;
        int uj = q.front().second;
        q.pop();

        for (int k = 0; k < 8; ++k)
        {
            int vi = ui + td[k];
            int vj = uj + tc[k];

            if (check(vi, vj) && a[vi][vj] == a[ui][uj] && !mark[vi][vj])
            {
                q.push(ii(vi, vj));
                mark[vi][vj] = true;
            }
            if (check(vi, vj) && a[vi][vj] > a[ui][uj]) flag = false;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }

    int cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!mark[i][j])
            {
                flag = true;
                bfs1(i, j);
                if (flag) cnt++;
            }
        }
    }


    cout << cnt;
}
