// got AC lol

#include <bits/stdc++.h>

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

void solve()
{
    string s; cin >> s;

    stack<int> st;

    for (char c : s)
    {
        if (c == '0')
        {
            if (st.size() < 1)
            {
                cout << "NO\n"; return;
            }

            if (st.size() < 2 || st.top() == 1)
            {
                cout << "NO\n"; return;
            }
            st.top() = 0;
        }
        
        if (c == '1')
        {
            if (st.size() < 1)
            {
               continue;
            }

            if (st.top() == 0)
            {
                cout << "NO\n"; return;
            }
            st.top() = 1;
        }

        if (c == '+')
        {
            if (st.size() < 1) st.push(1);
            else if (st.top() == 0) st.push(0);
            else st.push(2);
        }

        if (c == '-')
        {
            if (st.size() < 1)
            {
                cout << "NO\n"; return;
            }

            if (st.top() == 1 && st.size() > 1)
            {
                st.pop();
                st.top() = 1;
            }
            else if (st.size() >= 1)
            {
                st.pop();
            }
            else
            {
                cout << "NO\n"; return;
            }
        }
    }

    cout << "YES\n";
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("text");
    int test; cin >> test;
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

