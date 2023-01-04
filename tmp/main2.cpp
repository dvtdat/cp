#include <bits/stdc++.h>

using namespace std;

int main()
{
    int table[4][4];

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j) cin >> table[i][j];
    }

    cout << '\n';
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }

}
