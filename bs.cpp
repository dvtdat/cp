#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a = {2, 4, 5, 8, 9, 11, 13, 14, 16, 20};

    int n = a.size();

    int l = 0, r = n - 1;
    int X = 10;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (X == a[mid]) {
            cout << mid << '\n';
            return 0;
        } else if (X < a[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << "Not found\n";
}