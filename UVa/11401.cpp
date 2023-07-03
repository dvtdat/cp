#include <iostream>

using namespace std;

unsigned long long a[1000010];

void process()
{
    unsigned long long cntOdd = 1;
    unsigned long long cntEven = 0;
    a[0] = 0;
    a[1] = 1;

    for (int i = 1; i < 500000; ++i)
    {
        cntEven += 2 * i;
        cntOdd += 2 * i + 1;
        a[2 * i] = a[2 * (i - 1) + 1] + cntEven;
        a[2 * i + 1] = a[2 * i] + cntOdd;
    }
}

int main()
{
    process();

    int n;
    while (cin >> n && n >= 3)
    {
        cout << a[n - 3] << '\n';
    }
    return 0;
}