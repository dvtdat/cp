#include <bits/stdc++.h>

using namespace std;

int main() {
    auto gcd = [&](int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    };

    cout << gcd(10, 15) << '\n';
}