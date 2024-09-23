#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> array;

    for (int i = 0; i < n; ++i) {
        int u; cin >> u;
        if (u % 2 == 0) array.push_back(u);
    }

    sort(array.rbegin(), array.rend());

    if (array.size() > 0) {
        cout << array[0];
    } else {
        cout << -1 << '\n';
    }
}