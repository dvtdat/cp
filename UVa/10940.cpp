#include <bits/stdc++.h>

using namespace std;

const int maxN = 500010;

int arr[maxN];

int main()
{
    int n;
    int cnt = 2;
    arr[1] = 1;
    for (int i = 2; i < maxN; ++i)
    {
        if (cnt == i)
        {
            arr[i] = cnt;
            cnt = 2;
        }
        else
        {
            arr[i] = cnt;
            cnt += 2;
        }
    }

    while (cin >> n && n != 0)
    {
        cout << arr[n] << '\n';
    }
}