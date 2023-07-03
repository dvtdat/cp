// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

struct Store
{
    int cap, cent;
};

bool cmp(const Store& a, const Store& b)
{
    return (a.cent > b.cent);
}

long long cal(int gallon, vector<Store> store)
{
    long long res = 0;
    int i = 0;
    while (gallon != 0 && i < store.size())
    {
        res += min(store[i].cap, gallon) * store[i].cent;
        gallon -= min(store[i].cap, gallon);
        i++;
    }

    return res;
}


void solve()
{
    int n, m, r; cin >> n >> m >> r;
    vector<int> cows(n), rent(r);
    vector<Store> store(m);

    for (int i = 0; i < n; ++i) cin >> cows[i];
    for (int i = 0; i < m; ++i) cin >> store[i].cap >> store[i].cent;
    for (int i = 0; i < r; ++i) cin >> rent[i];

    sort(cows.rbegin(), cows.rend());
    sort(store.begin(), store.end(), cmp);
    sort(rent.rbegin(), rent.rend());

    vector<long long> pRent(r), pCows(n);
    pCows[0] = cows[0];
    for (int i = 1; i < n; ++i) pCows[i] = pCows[i - 1] + cows[i];
    pRent[0] = rent[0];
    for (int i = 1; i < r; ++i) pRent[i] = pRent[i - 1] + rent[i];

    long long res = pRent[min(n, r) - 1];
    for (int i = 0; i < n; ++i)
    {
        res = max(res, (long long)((min(n - i - 2, r - 1) >= 0 ? pRent[min(n - i - 2, r - 1)] : 0LL) + cal(pCows[i], store)));
        //cout << res << " " << (min(n - i - 2, r - 1) >= 0 ? pRent[min(n - i - 2, r - 1)] : 0) << " " << cal(pCows[i], store) << '\n';
    }

    cout << res << '\n';
}

int main()
{
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int test = 1; //cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//

