//

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 100010;
const ll MOD = 998244353;
const double eps = 1e-12;

struct segmentTree
{
    int size;
    vector<ll> sums;

    void init(int n)
    {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(size * 2, 0LL);
    }

    void update(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = v;
            return;
        }

        int mid = (lx + rx) / 2;

        if (i < mid) update(i, v, 2 * x + 1, lx, mid);
        else update(i, v, 2 * x + 2, mid, rx);

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    ll get(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || r <= lx) return 0;
        if (l <= lx && rx <= r) return sums[x];

        int mid = (lx + rx) / 2;

        return get(l, r, x, lx, mid) + get(l, r, x, mid, rx);
    }

    void update(int i, int v)
    {
        update(i, v, 0, 0, size);
    }

    ll get(int l, int r)
    {
        get(l, r, 0, 0, size);
    }
};

void solve()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
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

