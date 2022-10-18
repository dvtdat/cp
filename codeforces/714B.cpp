// sap dc mac chung dong phuc. voi' nguoi ay roi

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> a(n);

    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    int cnt = 0;
    vector<int> diff;

    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            cnt++;
            diff.push_back(a[i] - a[i - 1]);
        }
    }

    if (cnt > 2)
    {
        cout << "NO";
        return;
    }

    if (cnt == 0 || cnt == 1)
    {
        cout << "YES";
        return;
    }

    if (diff[0] == diff[1]) cout << "YES";
    else cout << "NO";

}

int main()
{
    //int test = 1; //cin >> test;
    //while (test--)

    solve();
}


