#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<double> b(m + k);


    for (int& i : a) cin >> i;
    for (double& i : b) cin >> i;

    for (int i = m; i < m + k; ++i) b[i] = (b[i] * 0.5 * (double)sqrt(2));

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = n - 1, cnt = 0;

    for (int j = m + k - 1; j >= 0; j--)
    {
        if (b[j] < a[i])
        {
            cnt++;
            if (i >= 1) i--; else break;
        }
    }

    cout << cnt;
}
