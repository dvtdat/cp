#include <bits/stdc++.h>

using namespace std;

const int maxN = 5000000;

int primeDivisor[maxN + 5];
int primeFactors[maxN + 5];

void sieve()
{
    for (int i = 0; i <= maxN; ++i) primeDivisor[i] = i;

    primeDivisor[1] = 1;
    for (int i = 2; i * i <= maxN; ++i)
    {
        if (primeDivisor[i] == i)
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                primeDivisor[j] = i;
            }
        }
    }
}

void dp()
{
    primeFactors[1] = 0;
    for (int i = 2; i <= maxN; ++i)
    {
        primeFactors[i] = primeFactors[i / primeDivisor[i]] + 1;
    }

    for (int i = 2; i <= maxN; ++i)
    {
        primeFactors[i] += primeFactors[i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    sieve();
    dp();

    while (n--)
    {
        int a, b; cin >> a >> b;
        cout << primeFactors[a] - primeFactors[b] << '\n';
    }
}
