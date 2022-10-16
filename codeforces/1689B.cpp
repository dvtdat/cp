#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> a(n);

    for (int &i : a) cin >> i;

    if (n == 1)
    {
        cout << -1 << '\n';
        return;
    }

    stack<int> st;
    vector<int> res;

    for (int i = n; i > 0; --i) st.push(i);

    int i = 0;
    while (i < n - 2)
    {
        if (a[i] != st.top())
        {
            res.push_back(st.top());
            st.pop();
            i++;
        }
        else
        {
            int tmp = st.top(); st.pop();
            res.push_back(st.top());
            res.push_back(tmp);
            st.pop();
            i = i + 2;
        }
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    if (res[n - 1] == a[n - 1] || res[n - 2] == a[n - 2]) swap(res[n - 1], res[n - 2]);

    for (int i : res) cout << i << ' ';

    cout << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
