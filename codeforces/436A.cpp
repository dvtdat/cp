// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

priority_queue<ii, vector<ii>, greater<ii>> pq1, pq3;
priority_queue<int> pq2, pq4;

int sol1(int n, int x)
{
    int cnt = 0;

    while (true)
    {
        if (pq2.empty()) break;
        x += pq2.top(); pq2.pop(); cnt++;
        while (pq1.size() && pq1.top().first <= x)
        {
            pq2.push(pq1.top().second);
            pq1.pop();
        }
        while (pq3.size() && pq3.top().first <= x)
        {
            pq4.push(pq3.top().second);
            pq3.pop();
        }

        if (pq4.empty()) break;
        x += pq4.top(); pq4.pop(); cnt++;
        while (pq1.size() && pq1.top().first <= x)
        {
            pq2.push(pq1.top().second);
            pq1.pop();
        }
        while (pq3.size() && pq3.top().first <= x)
        {
            pq4.push(pq3.top().second);
            pq3.pop();
        }
    }

    return cnt;
}

int sol2(int n, int x)
{
    int cnt = 0;

    while (true)
    {
        if (pq4.empty()) break;
        x += pq4.top(); pq4.pop(); cnt++;
        while (pq1.size() && pq1.top().first <= x)
        {
            pq2.push(pq1.top().second);
            pq1.pop();
        }
        while (pq3.size() && pq3.top().first <= x)
        {
            pq4.push(pq3.top().second);
            pq3.pop();
        }

        if (pq2.empty()) break;
        x += pq2.top(); pq2.pop(); cnt++;
        while (pq1.size() && pq1.top().first <= x)
        {
            pq2.push(pq1.top().second);
            pq1.pop();
        }
        while (pq3.size() && pq3.top().first <= x)
        {
            pq4.push(pq3.top().second);
            pq3.pop();
        }
    }

    return cnt;
}

void solve()
{
    int n, x; cin >> n >> x;

    for (int i = 0; i < n; ++i)
    {
        int t, u, v; cin >> t >> u >> v;
        if (t == 0) pq1.push(ii(u, v));
        else pq3.push(ii(u, v));
    }

    while (pq1.size() && pq1.top().first <= x)
    {
        pq2.push(pq1.top().second);
        pq1.pop();
    }

    while (pq3.size() && pq3.top().first <= x)
    {
        pq4.push(pq3.top().second);
        pq3.pop();
    }

    priority_queue<ii, vector<ii>, greater<ii>> pqt1 = pq1, pqt3 = pq3;
    priority_queue<int> pqt2 = pq2, pqt4 = pq4;

    int res1 = sol1(n, x);

    pq1 = pqt1;
    pq2 = pqt2;
    pq3 = pqt3;
    pq4 = pqt4;
    
    int res2 = sol2(n, x);

    cout << max(res1, res2);
    
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("text");
    int test = 1; //cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//

