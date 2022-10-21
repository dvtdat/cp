// tiet Giai Tich, khong can Giai Thich

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> a;

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        int tmp = c - '0';

        if (tmp == 2)
        {
            a.push_back(2);
        }
        else if (tmp == 3)
        {
            a.push_back(3);
        }
        else if (tmp == 4)
        {
            a.push_back(2);
            a.push_back(2);
            a.push_back(3);
        }
        else if (tmp == 5)
        {
            a.push_back(5);
        }
        else if (tmp == 6)
        {
            a.push_back(5);
            a.push_back(3);
        }
        else if (tmp == 7)
        {
            a.push_back(7);
        }
        else if (tmp == 8)
        {
            a.push_back(7);
            a.push_back(2);
            a.push_back(2);
            a.push_back(2);
        }
        else if (tmp == 9)
        {
            a.push_back(7);
            a.push_back(2);
            a.push_back(3);
            a.push_back(3);
        }
    }

    sort(a.rbegin(), a.rend());

    for (int i : a) cout << i;
}
