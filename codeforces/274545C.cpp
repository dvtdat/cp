// dau tai, dau mat', dau rang, dau dau`
// khong bang dau long`

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
    vector<int> val;

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
            val[x] = v;
            return;
        }

        int mid = (lx + rx) / 2;

        if (i < mid) set(i, v, 2 * x + 1, lx, mid);
        else set(i, v, 2 * x + 2, mid, rx);

        val[x] = val[2 * x + 1] + val[2 * x + 2];
    }

    int getSum(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || r <= lx) return 0;
        if (l <= lx && rx <= r) return val[x];

        int mid = (lx + rx) / 2;
        return getSum(l, r, 2 * x + 1, lx, mid) + getSum(l, r, 2 * x + 2, mid, rx);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int getSum(int l, int r)
    {
        return getSum(l, r, 0, 0, size);
    }
};

void solve()
{
    int n; cin >> n;

    segmentTree st;
    st.init(2 * n);

    vector<int> pos(n + 1, -1);
    vector<int> res(n);

    for (int i = 1; i <= n * 2; ++i)
    {
        int t; cin >> t;
        if (pos[t] == -1) pos[t] = i;
        else
        {
            res[t - 1] = st.getSum(pos[t], i);
            st.set(pos[t], 1);
        }
    }

    for (int i : res) cout << i << ' ';
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
