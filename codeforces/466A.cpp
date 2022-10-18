//vibing in A2

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    cout << min((n / m) * b + min(b, (n % m) * min(a, b)), n * a);
}
