#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int cnt = 0;

    if (a % 2 == 1) {
        cout << a << ' ';
        cnt++;
    }

    if (b % 2 == 1) {
        cout << b << ' ';
        cnt++;
    }

    if (c % 2 == 1) {
        cout << c << ' ';
        cnt++;
    }

    if (cnt == 0) cout << -1 << '\n';
    else cout << '\n';

    return 0;
}