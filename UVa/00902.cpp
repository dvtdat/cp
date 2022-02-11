//toi chi muon duoc hanh. phuc' thoi

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        map<string, int> _map;
        map<string, int>::iterator it;

        string s; cin >> s;
        for (int i = 0; i < s.length() - n + 1; ++i)
        {
            string tmp = s.substr(i, n);
            it = _map.find(tmp);
            if (it == _map.end()) _map.insert(pair<string, int>(tmp, 1));
            else it -> second += 1;
        }

        int mx = 0;
        string mxS;
        for (it = _map.begin(); it != _map.end(); ++it)
        {
            if (it -> second > mx)
            {
                mx = it -> second;
                mxS = it -> first;
            }
        }

        cout << mxS << '\n';
    }
}
