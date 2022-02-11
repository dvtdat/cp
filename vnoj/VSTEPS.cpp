//m dang kiem cai' gi` day homie?

#include <bits/stdc++.h>
#define N 100010
#define MOD 14062008

using namespace std;

int f[N];
bool mark[N];

int main()
{
    f[0] = 0; f[1] = 1;

    int n, k;
    cin >> n >> k;

    memset(mark, true, sizeof mark);
    for (int i = 0; i < k; ++i)
    {
        int tmp; cin >> tmp;
        mark[tmp] = false;
    }

    for (int i = 2; i <= n; ++i)
    {
        if (mark[i]) f[i] = (f[i - 1] + f[i - 2]) % MOD;
        else f[i] = 0;
    }


    cout << f[n];
}
