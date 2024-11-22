#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    int result = 1;
    for (int i : a) result *= i;

    return 0; 
}