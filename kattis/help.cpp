#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        vector<int> a(n);
        for (int& i : a) cin >> i;
        sort(a.begin(), a.end());

        cout << a[0] << "-A ";
        int tmp = 1;
        for (int i = n - 1; i > 0; i--)
        {
            cout << a[i] << "-" << (tmp % 2 == 0 ? "A " : "B ");
            tmp++;
        }
        cout << endl;
    }
}
