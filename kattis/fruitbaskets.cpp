#include <bits/stdc++.h>

using namespace std;

long long total = 0;
int n;

void backtrack(vector<int> a, int c, int s)
{
    if (s >= 200) return;
    if (c == n)
    {
        total -= s;
        return;
    }
    else
    {
        backtrack(a, c + 1, s);
        backtrack(a, c + 1, s + a[c]);
    }
}

int main()
{
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        total += a[i] * (long long)(pow(2, n - 1));
    }

    backtrack(a, 0, 0);

    cout << total;
}
