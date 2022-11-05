// chill dude
// my class suck
// my team suck
// everything suck

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
    string s; cin >> s;

    int cnt = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != s[i - 1])
        {
            if (cnt <= 1)
            {
                cout << "NO\n"; return;
            }
            cnt = 1;
        }
        else cnt++;
    }
    if (cnt <= 1)
    {
        cout << "NO\n"; return;
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}

