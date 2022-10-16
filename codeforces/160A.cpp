//lai nua, khong cam xuc

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> a(n);

    int sum = 0;
    for (int &i : a)
    {
        cin >> i;
        sum += i;
    }

    sort(a.rbegin(), a.rend());


    int tmp = 0, res = 1;
    for (int i = 0; i < n; ++i)
    {
        tmp += a[i];
        sum -= a[i];

        if (tmp > sum) break;
        res++;
    }

    cout << res;
}
