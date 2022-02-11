//xa hoi nay khong co' cho^~ cho ke? yeu^' :sadge:

#include <bits/stdc++.h>
#define inf INT_MAX
#define N 1010

using namespace std;

int a[N], f[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mx = 0;
    for (int i = 0; i < n; ++i)
    {
        f[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        }
        mx = max(mx, f[i]);
    }

    cout << mx << '\n';

}
