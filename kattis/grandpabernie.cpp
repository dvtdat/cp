#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    unordered_map<string, vector<int>> um;
    unordered_set<string> dest;

    for (int i = 0; i < n; ++i)
    {
        string tmp; cin >> tmp;
        int year; cin >> year;

        dest.insert(tmp);

        if (dest.count(tmp) < 1)
        {
            vector<int> v;
            v.push_back(year);
            um.insert({tmp, v});
        }
        else
        {
            vector<int> &v = um[tmp];
            v.push_back(year);
        }
    }

    for (auto d : dest)
    {
        vector<int> &v = um[d];
        sort(v.begin(), v.end());
    }

    int q; cin >> q;
    while (q--)
    {
        string tmp;
        int t;

        cin >> tmp >> t;

        vector<int> &v = um[tmp];

        cout << v[t - 1] << endl;
    }

}

