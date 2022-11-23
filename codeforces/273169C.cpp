// luc em nhin anh anh chot roi vao tram tu
// anh dau co muon minh chan chu
// con tim bi troi' nen gam gu`

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

struct item
{
    ll val;
    int cnt;
};

struct segmentTree
{
    int size;
    vector<item> mn;

    item merge(item a, item b)
    {
        if (a.val < b.val) return a;
        if (a.val > b.val) return b;
        else return {a.val, a.cnt + b.cnt};
    }

    item single(int v)
    {
        return {v, 1};
    }

    void init(int n)
    {
        size = 1;
        while (size < n) size *= 2;
        mn.resize(size * 2);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            mn[x] = {v, 1};
            return;
        }

        int mid = (lx + rx) / 2;

        if (i < mid) set(i, v, 2 * x + 1, lx, mid);
        else set(i, v, 2 * x + 2, mid, rx);

        mn[x] = merge(mn[2 * x + 1], mn[2 * x + 2]);
    }

    item getMin(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || l >= rx) return {infLL, 0};
        if (l <= lx && rx <= r) return mn[x];

        int mid = (lx + rx) / 2;
        item mn1 = getMin(l, r, 2 * x + 1, lx, mid);
        item mn2 = getMin(l, r, 2 * x + 2, mid, rx);

        return merge(mn1, mn2);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    item getMin(int l, int r)
    {
        return getMin(l, r, 0, 0, size);
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
            item res = st.getMin(l, r);
            cout << res.val << ' ' << res.cnt << '\n';
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

