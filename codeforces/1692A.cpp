#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    while (n--)
    {
        int a, b, c = 0;
        cin >> a;
        for (int i = 0; i < 3; ++i)
        {
            cin >> b;
            if (a < b) c++;
        }

        cout << c << endl;
    }
}
