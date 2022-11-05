// xac' o bach khoa, hon` o nhan van

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

void solve()
{
    int n, m; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    cin >> m;
    vector<int> b(m);
    for (int &i : b) cin >> i;

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    if (a[0] > b[0])
    {
        cout << "Alice\nAlice\n";
    }
    else if (b[0] > a[0])
    {
        cout << "Bob\nBob\n";
    }
    else cout << "Alice\nBob\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}
