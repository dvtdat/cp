#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    int cnt = 0;
    while (cin >> n && n != 0)
    {
        double res = 0.5 * (3 + (double)sqrt(9 + 8.0 * n));
        cout << "Case " << ++cnt << ": ";
        cout << (int)ceil(res) << '\n';
    }
}