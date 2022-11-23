// em van con thieu ngu sau nhung lan phai chay deadline
// em quen an quen uong, quen ca viec chai lai toc tai

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
    ll seg;
    ll pre;
    ll suf;
    ll sum;
};

struct segmentTree
{
    int size;
    vector<item> mn;

    item calc(item a, item b)
    {
        item c;
        c.seg = max(max(a.seg, b.seg), a.suf + b.pre);
        c.pre = max(a.pre, a.sum + b.pre);
        c.suf = max(b.suf, b.sum + a.suf);
        c.sum = a.sum + b.sum;

        return c;
    }

    item single(int v)
    {
        return {v, v, v, v, v};
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
            mn[x] = single(v);
            return;
        }

        int mid = (lx + rx) / 2;

        if (i < mid) set(i, v, 2 * x + 1, lx, mid);
        else set(i, v, 2 * x + 2, mid, rx);

        mn[x] = calc(mn[2 * x + 1], mn[2 * x + 2]);
    }

    item get(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || l >= rx) return single(0);
        if (l <= lx && rx <= r) return mn[x];

        int mid = (lx + rx) / 2;
        item mn1 = get(l, r, 2 * x + 1, lx, mid);
        item mn2 = get(l, r, 2 * x + 2, mid, rx);

        return calc(mn1, mn2);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    item get(int l, int r)
    {
        return get(l, r, 0, 0, size);
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

    cout << max(0LL, st.get(0, n).seg) << '\n';

    while (m--)
    {
        int i, v; cin >> i >> v;
        st.set(i, v);
        cout << max(0LL, st.get(0, n).seg) << '\n';
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


