// gdsc?

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

struct segmentTree
{
    int size;
    vector<long long> sums;

    void init(int n)
    {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0LL);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = v;
            return;
        }

        int m = (lx + rx) / 2;

        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return sums[x];

        int m = (lx + rx) / 2;

        long long s1 = sum(l, r, 2 * x + 1, lx, m);
        long long s2 = sum(l, r, 2 * x + 2, m, rx);

        return s1 + s2;
    }

    long long sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    segmentTree st;
    st.init(n);

    for (int i = 0; i < n; ++i)
    {
        int v; cin >> v;
        st.set(i, v);
    }

    for (int i = 0; i < m; ++i)
    {
        int op; cin >> op;
        if (op == 1)
        {
            int x, v; cin >> x >> v;
            st.set(x, v);
        }
        else
        {
            int l, r; cin >> l >> r;
            cout << st.sum(l, r) << '\n';
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
