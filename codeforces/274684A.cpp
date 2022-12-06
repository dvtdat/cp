// that dang suy ngam~

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
        while (size < n) size *= 2;
        val.assign(size * 2, 0);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            val[x] = v * (i % 2 == 0  ? -1 : 1);
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2 * x + 1, lx, mid);
        else set(i, v, 2 * x + 2, mid, rx);

        val[x] = val[2 * x + 1] + val[2 * x + 2];
    }

    ll sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return val[x];

        int m = (lx + rx) / 2;

        ll s1 = sum(l, r, 2 * x + 1, lx, m);
        ll s2 = sum(l, r, 2 * x + 2, m, rx);

        return s1 + s2;
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    ll sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }

    void debug()
    {
        for (int i = 0; i < size * 2 - 1; ++i) cout << val[i] << ' ';
    }
};

void solve()
{
    int n; cin >> n;

    segmentTree st;
    st.init(n);

    for (int i = 1; i <= n; ++i)
    {
        int v; cin >> v;
        st.set(i, v);
    }

    int m; cin >> m;

    while (m--)
    {
        int op; cin >> op;

        if (!op)
        {
            int i, v; cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r; cin >> l >> r;
            cout << st.sum(l, r + 1) * (l % 2 == 0 ? -1 : 1) << '\n';
        }
    }

    //st.debug();

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

