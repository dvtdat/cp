// polygon: canh-gac
// source: https://leetcode.com/problems/heaters/description/
// author: dvtd

// constraint: sum of N <= 2e5, sum of M <= 2e5

#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& cells, vector<int>& towers, int k) {
    int i, j;
    for (i = 0, j = 0; i < cells.size() && j < towers.size();) {
        if (abs(cells[i] - towers[j]) <= k) i++;
        else if (cells[i] < towers[j]) return false;
        else j++;
    }

    return (i == cells.size());
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> cells(n);
    vector<int> towers(m);

    for (int &cell : cells) cin >> cell;
    for (int &tower : towers) cin >> tower;

    sort(cells.begin(), cells.end());
    sort(towers.begin(), towers.end());

    int left = 0, right = 1e9 + 5;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(cells, towers, mid)) right = mid - 1;
        else left = mid + 1;
    }

    cout << left << '\n';
}

int main() {
    int test; cin >> test;
    while (test--) solve();
}
