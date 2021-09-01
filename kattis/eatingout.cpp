#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;

    if (2 * n - a - b >= c) cout << "possible";
    else cout << "impossible";
}
