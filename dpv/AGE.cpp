#include <bits/stdc++.h>
#define maxN 300

using namespace std;

typedef pair<int, int> ii;

int u, v, w;
int n, m, s1, s2;
vector<int> adj[maxN];

int main()
{
    cin >> n >> m >> s1 >> s2;

    while (m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> p1cur(n + 1, false), p2cur(n + 1, false);
    p1cur[s1] = p2cur[s2] = true;

    bool flag = false;
    int cnt = 0;

    while (!flag && cnt < 20 * n)
    {
        vector<bool> p1next(n + 1, false), p2next(n + 1, false);

        cnt++;

        for (int i = 1; i <= n;++i)
        {
            if (p1cur[i])
            {
                for (int x : adj[i])  p1next[x] =  true;
            }
        }

        for (int i = 1; i <= n;++i)
        {
            if (p2cur[i])
            {
                for (int x : adj[i])  p2next[x] =  true;
            }
        }

        for (int i = 1; i <= n; ++i) if (p1next[i] && p2next[i]) flag = true;

        p1cur = p1next;
        p2cur = p2next;
    }

    if (flag) cout << cnt;
    else cout << -1;
}
