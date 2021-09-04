#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, test = 0;
    while (cin >> n)
    {
        test++;
        cout << "Case " << test << ": " << floor(n * log10(1.5) + log10(3) + 1) << endl;
    }
}
