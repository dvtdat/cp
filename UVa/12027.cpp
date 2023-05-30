#include <bits/stdc++.h>

using namespace std;

int arr[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

int main()
{
    string s;
    while (cin >> s && s != "0")
    {
        int len = s.length();
        int val = 0;
        if (len % 2 == 0)
        {
            val = (s[0] - '0') * 10 + (s[1] - '0');;
        }
        else
        {
            val = (s[0] - '0');
        }

        int i = 1;
        while (val >= arr[i] && i < 10) i++; i--;
        cout << i;
        for (int i = 0; i < (len - 1) / 2; ++i) cout << 0; cout << '\n';
    }
}