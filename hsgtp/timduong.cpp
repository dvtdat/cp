#include <bits/stdc++.h>
#define inf INT_MAX
#define N 510

using namespace std;

typedef pair<int, int> ii;

int n;
int a[N][N], mark[N][N];
int td[4] = {1, -1, 0 , 0}, tc[4] = {0, 0, 1, -1};

bool check(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < n);
}

bool bfs(int mid)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) mark[i][j] = false;

    queue<ii> q;
    q.push(ii(0, 0));
    while (!q.empty())
    {
        int ui = q.front().first;
        int uj = q.front().second;
        q.pop();

        if (mark[ui][uj]) continue;
        mark[ui][uj] = true;

        for (int k = 0; k < 4; ++k)
        {
            int vi = ui + td[k];
            int vj = uj + tc[k];

            if (check(vi, vj) && abs(a[ui][uj] - a[vi][vj]) <= mid)
            {
                q.push(ii(vi, vj));
            }
        }
    }

    return mark[n - 1][n - 1];
}

int main()
{
    freopen("timduong.inp", "r", stdin);
    freopen("timduong.out", "w", stdout);
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }

    int l, r;
    l = 0; r = 1000010;
    int ans = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        //cout << mid << endl;
        if (bfs(mid))
        {
            ans = mid; r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans;
}
