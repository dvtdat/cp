// mac. do` the duc. j xinh z >~<

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

void solve()
{
    int n; cin >> n;
    vector<ii> a(n);
    vector<int> b(n), c(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        b[i] = a[i].first;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].second;
        c[i] = a[i].second;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i].first > a[i + 1].first || a[i].second > a[i + 1].second)
        {
            cout << "-1\n";
            return;
        }
    }

    vector<ii> res;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (b[i] > b[j] || c[i] > c[j])
            {
                res.push_back(ii(i + 1, j + 1));
                swap(b[i], b[j]);
                swap(c[i], c[j]);
            }
        }
    }

    cout << res.size() << '\n';
    for (ii i : res) cout << i.first << ' ' << i.second << '\n';

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}


