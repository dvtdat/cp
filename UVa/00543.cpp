#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000010;

vector<int> prime;
int isPrime[maxN];

void sieve()
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (long long i = 2; i < maxN; ++i)
    {
        if (isPrime[i])
        {
            for (long long j = i * i; j < maxN; j += i) isPrime[j] = 0;
            prime.push_back((int)i);
        }
    }
}

int main()
{
    sieve();

    int n; 
    while (cin >> n && n != 0)
    {
        int i;
        bool flag = false;
        for (i = 1; i < prime.size(); ++i)
        {
            if (isPrime[n - prime[i]] && n - prime[i] != 2)
            {
                flag = true;
                break;
            }
        }
        if (flag && n - prime[i] > 0) cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
        else cout << "Goldbach's conjecture is wrong.\n";
    }
}