// hackathon incomming

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
        while (size <= n) size *= 2;
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

    int findVal(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1) return lx;

        int mid = (lx + rx) / 2;

        if (k > val[2 * x + 2]) findVal(k - val[2 * x + 2], 2 * x + 1, lx, mid);
        else findVal(k, 2 * x + 2, mid, rx);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int findVal(int k)
    {
        return findVal(k, 0, 0, size);
    }
};

void solve()
{
    int n; cin >> n;

    segmentTree st;
    st.init(n);

    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) st.set(i, 1);

    vector<int> res;

    for (int i = n - 1; i >= 0; --i)
    {
        int t = st.findVal(a[i] + 1);
        res.push_back(t);
        st.set(t, 0);
    }

    reverse(res.begin(), res.end());
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

