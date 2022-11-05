#include <bits/stdc++.h>

using namespace std;

void f(vector<int> &b)
{
    for (int &i : b) i += 10;
}

int main()
{
    int n; cin >> n;

    vector<int> a(n);

    for (int &i : a) cin >> i;

    // for (int i = 0; i < n; ++i) cin >> a[i];

    f(a);

    for (int i : a) cout << i << ' ';


}
