// lai nua~, khong cam xuc

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);

    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    int res = 1;

    for (int i = 0; i < n; ++i)
    {
        res += a[i] >= res ? 1 : 0;
    }

    cout << res;
}
