#include <bits/stdc++.h>

using namespace std;

int main()
{
    int L, f;
    cout << fixed << setprecision(8);

    while (cin >> L >> f && L != 0 && f != 0)
    {    
        cout << 1.0 * sqrt(2.0 * L * f) << ' ';
        cout << 7200.0 * f * sqrt(2.0 * L * f) / (4.0 * L * f) << '\n';
    }
}