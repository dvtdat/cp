#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    n--;

    k = (int) floor(k / m);

    cout << (int) ceil((double)(n / k)) + (n % k != 0 ? 1 : 0);
}
