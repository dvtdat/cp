#include <bits/stdc++.h>
#define maxN 1000010

using namespace std;

int ft[maxN];
int n, k;

int sum(int idx)
{
    int total = 0;
    for (int i = idx; i > 0; i &= i-1) total += ft[i - 1];

    return total;
}

void update(int idx, int val)
{
    for (int i = idx; i < n; i |= i+1) ft[i] += val;
}

int getval(int idx)
{
    return sum(idx + 1) - sum(idx);
}

int main()
{
    cin >> n >> k;

    memset(ft, 0 ,sizeof ft);

    for(int i = 0; i < k; i++)
    {
        char c;
        cin >> c;

        if(c == 'F')
        {
            int x; cin >> x;

            int val = getval(x);

            if(val == 0) val = 1;
            else val = -1;

            update(x, val);

            val = getval(x);
        }
        if(c == 'C')
        {
            int x, y;
            cin >> x >> y;
            cout << sum(y + 1) - sum(x) << endl;
        }
    }
}
