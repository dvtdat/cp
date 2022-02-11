//gioi? thi` xem 10 nam nua m o dau?

#include <bits/stdc++.h>

using namespace std;

string f[110];

string sum(string a, string b)
{
    int s, c = 0;
    string res = "";

    while (a.length() < b.length()) a = '0' + a;
    while (a.length() > b.length()) b = '0' + b;

    for (int i = a.length() - 1; i >= 0; --i)
    {
        s = (a[i] - '0') + (b[i] - '0') + c;
        c = s / 10;
        res = (char)((s % 10) + '0') + res;
    }

    if (c == 1) res = '1' + res;
    return res;
}


int main()
{
    f[1] = "1"; f[2] = "2";
    for (int i = 3; i <= 100; ++i) f[i] = sum(f[i - 1], f[i - 2]);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        cout << f[n] << '\n';
    }

}
