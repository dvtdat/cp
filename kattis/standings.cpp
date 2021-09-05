#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test; cin >> test;
    while (test--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            string tmp; cin >> tmp >> a[i];
        }

        sort(a.begin(), a.end());

        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += 1LL * abs(i + 1 - a[i]);
        }

        cout << sum << endl;
    }
}
