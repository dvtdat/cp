//toi chi muon duoc hanh. phuc' thoi

#include <bits/stdc++.h>
#define inf INT_MAX

using namespace std;

int main()
{
    int test; cin >> test;
    while (test--)
    {
        int n; cin >> n;
        vector<int> a(n);
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            for (int j = 0; j < i; ++j) if (a[j] <= a[i]) res++;
        }
        cout << res << '\n';
    }
}



