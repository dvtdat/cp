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

struct Cow
{
    int l, r;
};

bool cmp(const Cow& a, const Cow& b)
{
    return a.l < b.l;
}

void solve()
{
    int n; cin >> n;

    vector<Cow> cows(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> cows[i].l >> cows[i].r;
    }

    sort(cows.begin(), cows.end(), cmp);

    int total = 0;
    int left = 0, right = 0;

    for (int i = 0; i < n; ++i)
    {
        if (cows[i].r > right)
        {
            left = max(right, cows[i].l);
            right = cows[i].r;
            total += right - left;
        }
    }

    cows.push_back({cows[n - 1].r, 0});

    int mn = total;
    right = 0;

    for (int i = 0; i < n; ++i)
    {
        int tmp = min(cows[i + 1].l, cows[i].r) - max(right, cows[i].l);
        mn = min(mn, tmp);
        right = max(right, cows[i].r);
    }

    cout << total - max(mn, 0) << '\n';
}

int main()
{
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//

