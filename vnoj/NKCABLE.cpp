//silly me haha

#include <bits/stdc++.h>
#define N 25100

using namespace std;

int f[N], a[N];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a[i];
    }

    int cnt = 1;
    f[1] = a[0];

    for (int i = 2; i < n; ++i)
    {
        cnt++;
        if (cnt <= 2)
        {
            f[i] = f[i - 1] + a[i - 1];
        }
        else
        {
            if (f[i - 2] < f[i - 1])
            {
                cnt = 2;
                f[i] = f[i - 2] + a[i - 1];
            }
            else
            {
                f[i] = f[i - 1] + a[i - 1];
            }
        }
    }

    cout << f[n - 1];
}
