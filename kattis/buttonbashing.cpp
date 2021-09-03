#include <bits/stdc++.h>
#define inf INT_MAX

using namespace std;


int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> adj(n);
        vector<int> d(3700, inf);

        for (int& i : adj) cin >> i;

        queue<int> q;
        q.push(0);
        d[0] = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int i : adj)
            {
                int v = u + i;
                v = max(v, 0);
                v = min(v, 3600);
                if (d[v] > d[u] + 1)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }

        for (int i = k; i <= 3600; ++i)
        {
            if (d[i] != inf)
            {
                cout << d[i] << ' ' << i - k << endl;
                break;
            }
        }
    }
}
