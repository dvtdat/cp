// dau` toan` gau` khong ak, ngua'

#include <bits/stdc++.h>

using namespace std;

void process(vector<int> &a, int n)
{
    for (int &i : a) i += n * 2;
}

int main()
{
    int n; cin >> n;

    vector<int> a(n);

    for (int &i : a) cin >> i;

    process(a, n);

    vector<int*> ptr(n);

    for (int i = 0; i < n; ++i) ptr[i] = &a[i];

    for (auto i : ptr) cout << i << ' ';

}
