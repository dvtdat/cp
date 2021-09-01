#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    cout << ((b + 360 - a) % 360 <= 180 ? (b + 360 - a) % 360 : (b + 360 - a) % 360 - 360);
}
