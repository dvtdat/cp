// nho' :(

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
    vector<int> a(n * 2);

    for (int i = 0; i < n * 2; ++i)
    {
        cin >> a[i];
        if (pos[a[i]] == -1)
        {
            pos[a[i]] = i + 1;
            st.set(i + 1, 1);
        }
        else
        {
            st.set(pos[a[i]], 0);
            res[a[i] - 1] = st.getSum(pos[a[i]], i + 1);
        }
    }

    st.init(2 * n);
    pos.assign(n + 1, -1);
    reverse(a.begin(), a.end());

    for (int i = 0; i < n * 2; ++i)
    {
        if (pos[a[i]] == -1)
        {
            pos[a[i]] = i + 1;
            st.set(i + 1, 1);
        }
        else
        {
            st.set(pos[a[i]], 0);
            res[a[i] - 1] += st.getSum(pos[a[i]], i + 1);
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

