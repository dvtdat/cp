#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    while (cin >> n && n >= 0)
    {
        cout << (long long)(n * (n + 1) / 2 + 1) << '\n'; 
    }
}