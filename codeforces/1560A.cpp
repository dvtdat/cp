//toi bun`

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a;
    for (int i = 1; i <= 2000; i++)
    {
        if (i % 3 != 0 && i % 10 != 3) a.push_back(i);
    }
    int test; cin >> test;
    while (test--)
    {
        int n; cin >> n;
        cout << a[n - 1] << endl;
    }

}
