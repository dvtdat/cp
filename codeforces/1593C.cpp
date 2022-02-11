//toi that bai

#include <bits/stdc++.h>
#define inf INT_MAX

using namespace std;

void solve()
{
    int n, k;
    cin >> k >> n;

    vector<int> v;

    int tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        v.push_back(k - tmp);
    }

    sort(v.begin(), v.end());

    int i = 0; tmp = 0;
    while (i < n && tmp + v[i] < k)
    {
        tmp += v[i]; i++;
    }

    cout << i << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}




