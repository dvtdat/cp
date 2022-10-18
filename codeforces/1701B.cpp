// expert == co' ny

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> a(n + 10, 0);

    cout << 2 << '\n';
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j *= 2)
        {
            if (!a[j])
            {
                cout << j << ' ';
                a[j] = 1;
            }
        }
    }

    cout << '\n';

}

int main()
{
    int test; cin >> test;
    while (test--)

    solve();
}




