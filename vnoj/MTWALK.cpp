//start from the beginning

#include <bits/stdc++.h>
#define N 110
#define inf INT_MAX

using namespace std;

typedef pair<int, int> ii;

int n;
int a[N][N];
bool d[N][N];
int td[4] = {0, 0, 1, -1},
    tc[4] = {1, -1, 0, 0};

int check(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool bfs(int mid)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) d[i][j] = false;
    d[0][0] = true;

    queue<ii> q; q.push(ii(0, 0));

    while(!q.empty())
    {
        int ui = q.front().first;
        int uj = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int vi = ui + td[k];
            int vj = uj + tc[k];

            if (check(vi, vj) && abs(a[ui][uj] - a[vi][vj]) <= mid && !d[vi][vj])
            {
                q.push(ii(vi, vj));
                d[vi][vj] = true;
            }
        }
    }

    return d[n - 1][n - 1];
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }

    int l = 0, r = 1000;
    int res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (bfs(mid)) res = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << res;
}
