//xa hoi nay khong co' cho^~ cho ke? yeu^' :sadge:

#include <bits/stdc++.h>
#define inf INT_MAX
#define N 60010

using namespace std;

int r[N], t[N], f[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int i = 0; i < n - 1; ++i) cin >> r[i];

    f[n - 1] = t[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        f[i] = min(f[i + 1] + t[i], f[i + 2] + r[i]);
    }

    cout << f[0] << '\n';

}
