// chang nghi suy, chang dan do, chang muon lam gi

#include <bits/stdc++.h>
#define inf 2e9
#define N 1000100

using namespace std;

typedef pair<string, int> is;

vector<is> _list;

bool check(string a, string b)
{
    if (a.size() > b.size()) return false;
    else return b.substr(0, a.size()) == a;
}

int main()
{
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout);

    int w, n; cin >> w >> n;

    for (int i = 0; i < w; ++i)
    {
        string s; cin >> s;
        _list.push_back(is(s, i));
    }

    sort(_list.begin(), _list.end());

    for (int i = 0; i < n; ++i)
    {
        string s;
        int k;
        cin >> k >> s; k--;

        int pos = lower_bound(_list.begin(), _list.end(), is(s, 0)) - _list.begin() + k;

        if (pos < w && check(s, _list[pos].first)) cout << _list[pos].second + 1; else cout << -1;
        cout << '\n';

    }
}
