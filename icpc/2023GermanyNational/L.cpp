#include <bits/stdc++.h>

using namespace std;

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
    setIO("t");

    string s; cin >> s;
    stack<char> st;

    vector<string> v;
    stringstream ss;

    st.push(s[0]);
    ss << s[0];
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == '(') st.push(s[i]);
        else st.pop();

        ss << s[i];

        if (st.empty())
        {
            v.push_back(ss.str());
            ss.str("");
        }
    }

    string res = "";
    string tmp = v[0];
    for (int i = 0; i < v.size() - 1; ++i)
    {
        res += v[i + 1];
    }
    res += v[0];

    if (res == s) cout << "no\n";
    else cout << res << '\n';

    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
