// cold cold cold cold cold
// hungry hungry hungry hungary

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
    vector<int> mx;

    void init(int n)
    {
        size = 1;
        while (size < n) size *= 2;
        mx.assign(size * 2, 0);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            mx[x] = v;
            return;
        }

        int mid = (lx + rx) / 2;

        if (i < mid) set(i, v, 2 * x + 1, lx, mid);
        else set(i, v, 2 * x + 2, mid, rx);

        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
    }

    int findMax(int k, int l, int x, int lx, int rx)
    {
        if (mx[x] < k) return -1;
        if (rx <= l) return -1;
        if (rx - lx == 1) return lx;

        int mid = (lx + rx) / 2;

        int res = findMax(k, l, 2 * x + 1, lx, mid);
        if (res == -1) res = findMax(k, l, 2 * x + 2, mid, rx);

        return res;
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int findMax(int k, int l)
    {
        return findMax(k, l, 0, 0, size);
    }
};

void solve()
{
    int n, q; cin >> n >> q;

    segmentTree st;
    st.init(n);

    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        int v; cin >> v;
        a[i] = v;
        st.set(i, v);
    }

    while (q--)
    {
        int op; cin >> op;
        if (op == 1)
        {
            int i, v; cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int k, l; cin >> k >> l;
            cout << st.findMax(k, l) << '\n';
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

