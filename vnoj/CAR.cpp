//mang tien` ve` cho me.

#include <bits/stdc++.h>
#define N 10100

using namespace std;

typedef struct
{
    int a, b, i;
    float f;
} type;

bool cmp(const type & x, const type & y)
{
    return x.f < y.f;
}

int main()
{
    int n; cin >> n;
    vector<type> arr(n);

    for (type &i : arr) cin >> i.a;
    for (type &i : arr) cin >> i.b;
    for (int i = 0; i < n; ++i)
    {
        arr[i].f = (float) arr[i].a / arr[i].b;
        arr[i].i = i;
    }

    sort(arr.rbegin(), arr.rend(), cmp);

    long long res = 0, t = 0;
    for (type i : arr)
    {
        t += i.b;
        res += i.a * t;
    }

    cout << res << '\n';

    for (type i : arr)
    {
        cout << i.i + 1 << ' ';
    }

}
