// 3 tieng lien tuc suffer roi

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m; cin >> n >> m;

    vector<int> a;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            a.push_back(max(i, n - i - 1) + max(j, m - j - 1));
        }
    }

    sort(a.begin(), a.end());

    for (int i : a) cout << i << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}


