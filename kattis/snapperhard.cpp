#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test; cin >> test;
    for (int i = 1; i <= test; ++i)
    {
        int n, k; cin >> n >> k;

        bool flag = true;
        for (int j = 0; j < n; ++j)
        {
            if (k % 2 == 0) flag = false;
            k /= 2;
        }

        cout << "Case #" << i << ": " << (flag ? "ON" : "OFF") << endl;
    }
}
