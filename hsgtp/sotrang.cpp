#include <bits/stdc++.h>
#define N 1000000

using namespace std;

int a[N];

int main()
{
    int n;
    cin >> n;

    memset(a, 0, sizeof a);

    a[10] = 1;
    a[100] = 1;
    a[1000] = 1;
    a[10000] = 1;
    a[100000] = 1;

    a[4] = 1;

    for (int i = 4; i < 1000000; ++i)
    {
        a[i] += a[i - 1]; //cout << i << ' ' << a[i] << '\n';
    }


    int i = 4, tmp = 1;

    while (tmp != n)
    {
        i++;
        tmp += a[i];
    }

    cout << i;
}
