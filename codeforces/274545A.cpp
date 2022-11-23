// england vs irun (v2)

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
    vector<int> sum;

    void init(int n)
    {
        size = 1;
        while (size <= n + 1) size *= 2;
        sum.assign(size * 2, 0);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sum[x] = v;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2 * x + 1, lx, mid);
        else set(i, v, 2 * x + 2, mid, rx);

        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
    }

    int getSum(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || r <= lx) return 0;
        if (l <= lx && rx <= r) return sum[x];

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
    st.init(n);

    for (int i = 0; i < n; ++i)
    {
        int t; cin >> t;
        cout << st.getSum(t, n + 1) << ' ';
        st.set(t, 1);
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

