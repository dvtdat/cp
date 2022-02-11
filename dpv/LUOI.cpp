//chi la ao giac anh da khoc khi anh mat em

#include <bits/stdc++.h>
#define maxN 1001

using namespace std;

int td[4] = {1, -1, 0, 0};
int tc[4] = {0, 0, 1, -1};
char a[maxN][maxN];
bool mark[maxN][maxN];
int b[maxN][maxN], s[maxN];

int n, m, cnt = 0;

bool check(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int i, int j)
{
    b[i][j] = cnt;
    s[cnt] += 1;
    for (int k = 0; k < 4; ++k)
    {
        int u = i + td[k];
        int v = j + tc[k];
        if (check(u, v) && b[u][v] == 0 && (a[u][v] == a[i][j])) dfs(u, v);
    }
}

int main()
{
    freopen("LUOI.INP", "r", stdin);
    freopen("LUOI.OUT", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (b[i][j] == 0)
            {
                cnt += 1;
                dfs(i, j);
            }
        }
    }

    cout << cnt << endl;

    for (int i = 1; i <= cnt; ++i) cout << s[i] << ' '; cout << endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) cout << b[i][j] << ' ';
        cout << endl;
    }
}
