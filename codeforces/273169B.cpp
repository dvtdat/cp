// nhung con song' xo lau dai vo~ trong bong' dem
// noi~ dau cu' nhu dang voi. ghe' tham trai' tim
// chieu hoang hon den mang theo may den ve
// phu kin trong tam tu bong hinh em

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
    vector<long long> mn;

    void init(int n)
    {
        size = 1;
        while (size < n) size *= 2;
        mn.assign(size * 2, infLL);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            mn[x] = v;
            return;
        }

        int m = (lx + rx) / 2;

        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);

        mn[x] = min(mn[2 * x + 1], mn[2 * x + 2]);
    }

    long long getMin(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l) return infLL;
        if (lx >= l && rx <= r) return mn[x];

        int m = (lx + rx) / 2;

        long long mn1 = getMin(l, r, 2 * x + 1, lx, m);
        long long mn2 = getMin(l, r, 2 * x + 2, m, rx);

        return min(mn1, mn2);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    long long getMin(int l, int r)
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
            cout << st.getMin(l, r) << '\n';
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
