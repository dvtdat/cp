// croatia vs morocco

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
    vector<ll> val;

    void init(int n)
    {
        size = 1;
        while (size <= n) size *= 2;
        val.assign(size * 2, 0LL);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            val[x] += v;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2 * x + 1, lx, mid);
        else set(i, v, 2 * x + 2, mid, rx);

        val[x] = val[2 * x + 1] + val[2 * x + 2];
    }

    ll getSum(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || r <= lx) return 0;
        if (l <= lx && rx <= r) return val[x];

        int mid = (lx + rx) / 2;
        return getSum(l, r, 2 * x + 1, lx, mid) + getSum(l, r, 2 * x + 2, mid, rx);
    }

    void set(int x, int y, int v)
    {
        set(x - 1, v, 0, 0, size);
        set(y - 1, -v, 0, 0, size);
    }

    ll getSum(int l, int r)
    {
        return getSum(l, r, 0, 0, size);
    }

    void debug()
    {
        for (int i = 0; i < size * 2; ++i) cout << val[i]; cout << '\n';
    }
};

void solve()
{
    int n, q; cin >> n >> q;

    segmentTree st;
    st.init(n);

    while (q--)
    {
        int op; cin >> op;
        if (op == 1)
        {
            int x, y, v; cin >> x >> y >> v;
            st.set(++x, ++y, v);
            //st.debug();
        }
        else
        {
            int i; cin >> i;
            cout << st.getSum(0, ++i) << '\n';
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
//
//

