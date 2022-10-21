// cant complain (again)

#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> ii;

void solve()
{
    long long n, k, r;
    cin >> n >> k >> r;

    r *= n;

    long long sum = 0;

    vector<ii> a(n);
    for (long long i = 0; i < n; ++i)
    {
        cin >> a[i].second >> a[i].first;

        sum += a[i].second;
        a[i].second = k - a[i].second;
        a[i].second = -a[i].second;
    }

    sort(a.begin(), a.end());

    long long i = 0, res = 0;
    while (sum < r )
    {
        res += a[i].first * min(r - sum, -a[i].second);
        sum += min(r - sum, -a[i].second);
        i++;
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}

