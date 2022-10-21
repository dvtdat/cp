// sao nao~ be' z :(

#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> ii;

void solve()
{
    int n; cin >> n;

    vector<int> a(n);

    for (int &i : a)
    {
        cin >> i;
    }

    sort(a.begin(), a.end());

    for (int k = n; k >= 1; k--)
    {
        bool ok = true;

        for (int i = 0; i < n; ++i)
        {
            if (a[i] < i / k)
            {
                cout << k + 1;
                return;
            }
        }
    }

    cout << 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}


