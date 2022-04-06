// va mot ngay dep troi minh ra khoi

#include <bits/stdc++.h>
#define inf INT_MAX
#define N 100100

using namespace std;

int par[N], a[N];

int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        par[a[i]]++;
    }

    queue<int> q;
    int cnt = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (par[i] == 0) q.push(i), cnt++;
    }

    while(!q.empty())
    {
        int i = q.front(); q.pop();
        if (par[a[i]] == 1)
        {
            q.push(a[i]);
            cnt++;
        }
        par[a[i]]--;
    }

    cout << n - cnt;
}
