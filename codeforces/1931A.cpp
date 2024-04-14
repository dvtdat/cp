#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= 26; ++i) {
        for (int j = 1; j <= 26; ++j) {
            for (int k = 1; k <= 26; ++k) {
                if (i + j + k == n) {
                    string res = "";
                    res += (char)(i + 'a' - 1);
                    res += (char)(j + 'a' - 1);
                    res += (char)(k + 'a' - 1);
                    cout << res << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    int test; cin >> test;

    while (test--) {
        solve();
    }
}