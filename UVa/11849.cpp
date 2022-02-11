#include <bits/stdc++.h>

using namespace std;

int process(const set<int> &a, const set<int> &b)
{
    int cnt = 0;
    for (set<int>::iterator i = b.begin(); i != b.end(); ++i)
    {
        if (a.find(*i) != a.end()) ++cnt;
    }

    return cnt;
}

void solve(int n, int m)
{
    set<int> first, second;
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp; first.insert(tmp);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> tmp; second.insert(tmp);
    }

    if (first.size() > second.size()) cout << process(first, second);
    else cout << process(second, first);

    cout << '\n';
}

int main()
{
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) solve(n, m);
}
