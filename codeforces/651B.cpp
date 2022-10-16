// troi` lanh. that.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> a(1001);

    for (int i = 0; i < n; ++i)
    {
        int tmp; cin >> tmp;
        a[tmp]++;
    }

    sort(a.begin(), a.end());

    cout << n - a[a.size() - 1];
}
