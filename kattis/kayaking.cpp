#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> is;
typedef long long ll;

int a, b, c, n;
int sa, sb, sc;

void low(string s, ll& a, ll& b, ll& c)
{
    for (char ch : s)
    {
        if (ch == 'a') a--;
        else if (ch == 'b') b--;
        else c--;
    }
}

bool ok(string s, ll a, ll b, ll c)
{
    low(s, a, b, c);
    return (a >= 0 && b >= 0 && c >= 0);
}

bool check(vector<int> v, vector<is> s, ll mid)
{
    ll _a = a;
    ll _b = b;
    ll _c = c;

    for (int i : v)
    {
        bool flag = false;
        for (is j : s)
        {
            if (i * j.first >= mid && ok(j.second, _a, _b, _c))
            {
                low(j.second, _a, _b, _c);
                flag = true;
                break;
            }
        }
        if (!flag) return false;
    }

    return true;
}

int main()
{
    cin >> a >> b >> c;
    cin >> sa >> sb >> sc;

    n = (a + b + c) / 2;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<is> s = {{sa + sb, "ab"}, {sa + sc, "ac"}, {sb + sc, "bc"},
                    {sa + sa, "aa"}, {sb + sb, "bb"}, {sc + sc, "cc"}};

    sort(s.begin(), s.end());

    ll l = 0, r = LONG_MAX, ans;

    while (l <= r)
    {
        ll mid = (l + r) / 2;

        if (check(v, s, mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
}
