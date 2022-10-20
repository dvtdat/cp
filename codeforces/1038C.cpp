// dau lung, moi goi', te tay

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> a(n), b(n);

    long long res1 = 0, res2 = 0;

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    a.push_back(0);
    b.push_back(0);

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    bool flag = true;
    int i = 0, j = 0;

    while ((i + j) != n * 2)
    {
        if (flag)
        {
            if (a[i] >= b[j]) res1 += a[i++];
            else j++;
        }
        else
        {
            if (b[j] >= a[i]) res2 += b[j++];
            else i++;
        }

        flag = !flag;
    }

    cout << res1 - res2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}



