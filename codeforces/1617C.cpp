// doi' bung.

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void solve()
{
    int n; cin >> n;

    vector<int> a;
    set<int> s;

    for (int i = 1; i <= n; ++i) s.insert(i);
    for (int i = 0; i < n; ++i)
    {
        int tmp; cin >> tmp;
        if (s.find(tmp) != s.end()) s.erase(tmp);
        else a.push_back(tmp);
    }

    sort(a.rbegin(), a.rend());

    for (int i = 0; i < a.size(); ++i)
    {
        auto it = s.end(); it--;

        int tmp = *it;
        if ((a[i] - 1) / 2 < tmp)
        {
            cout << -1 << '\n';
            return;
        }
        s.erase(it);
    }

    cout << a.size() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}

