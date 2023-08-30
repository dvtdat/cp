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

void solve()
{
    int n; cin >> n;

    priority_queue<ii> pq; // prioritize pq[x] = {increasing of size, decreasing of index}
    vector<int> res(n + 1);
    int cnt = 0;

    pq.push(ii(n, -1));

    while (cnt != n)
    {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();

        y = -y;

        if (x == 1)
        {
            res[y] = ++cnt;
            continue;
        }

        if (x == 2)
        {
            res[y] = ++cnt;
            pq.push(ii(1, -(y + 1)));
            continue;
        }

        int d = (x - 1) / 2 + y;
        res[d] = ++cnt;

        pq.push(ii((x - 1) / 2, -y));
        pq.push(ii(x / 2, -(d + 1)));
    }

    for (int i = 1; i <= n; ++i) cout << res[i] << ' '; cout << '\n';
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
    int test; cin >> test;
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

