#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

int main()
{
    ll n; cin >> n;

    map<ll, ll> m;
    for (ll i = 2; i <= min((ll)sqrt(n), (ll)100000); i++)
    {
        while (n % i == 0)
        {
            m[i]++;
            n /= i;
        }
    }

    if (n > 1) m[n]++;

    ll res = 1;
    for (auto& i : m)
    {
        while (i.second >= 9)
        {
            i.second -= 9;
            res *= i.first;
        }
    }

    cout << res;
}
