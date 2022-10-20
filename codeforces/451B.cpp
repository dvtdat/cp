// 3 tieng lien tuc suffer roi

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> a(n);

    for (int &i : a) cin >> i;

    vector<int> b = a;
    sort(a.begin(), a.end());

    vector<int> tmp;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            tmp.push_back(i); break;
        }
    }

    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] != b[i])
        {
            tmp.push_back(i); break;
        }
    }

    if (tmp.size() ==  0)
    {
        cout << "yes\n1 1";
        return;
    }

    int mn = b[tmp[0]];
    for (int i = tmp[0]; i <= tmp[1]; ++i)
    {
        if (b[i] <= mn) mn = b[i];
        else
        {
            cout << "no"; return;
        }
    }

    cout << "yes\n" << tmp[0] + 1 << ' ' << tmp[1] + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}

