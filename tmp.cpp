#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4 + 5;

int c[maxN][maxN];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }

    vector<int> mA(n, 0), mB(n, 0), mC(2 * n - 1, 0), mD(2 * n - 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mA[i] = max(mA[i], c[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mB[i] = max(mB[i], c[j][i]);
        }
    }

    for (int k = -(n - 1); k <= n - 1; ++k) {
        for (int i = 0; i < n; ++i) {
            if (i + k < 0 || i + k > n - 1) continue;
            mC[k + n] = max(mC[k + n], c[i][i + k]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mD[i + j] = max(mD[i + j], c[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (c[i][j] == max(mA[i], max(mB[j], max(mC[j - i + n], mD[i + j])))) cnt++;
        }
    }

    cout << cnt << '\n';
}