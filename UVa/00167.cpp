#include <bits/stdc++.h>
#define inf INT_MAX

using namespace std;

int row[8], a, b, _mx;
int table[8][8];

bool ok(int r, int c)
{
    for (int _c = 0; _c < c; ++_c)
    {
        if (row[_c] == r || abs(row[_c] - r) == abs(_c - c)) return false;
    }
    return true;
}

void backtrack(int c)
{
    if (c == 8 && row[b] == a)
    {
        int tmp = 0;
        for (int i = 0; i < 8; ++i) tmp += table[i][row[i]];
        _mx = max(_mx, tmp);
        //printf("%d %d\n", i + 1, row[i] + 1);
        //printf("\n");
    }
    for (int r = 0; r < 8; ++r)
    {
        if (ok(r, c))
        {
            row[c] = r; backtrack(c + 1);
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        //memset(table, 0, sizeof table);
        memset(row, 0, sizeof row);

        _mx = -inf;

        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                cin >> table[i][j];
            }
        }

        a = 0;
        for (int b = 0; b < 8; ++b) backtrack(0);

        cout << _mx << '\n';
    }
}
