//the nay thi` sao gap dc em day :(

#include <bits/stdc++.h>
#define maxN 200010

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

vector<ii> indices;

int main()
{
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int l, r; cin >> l >> r;
        indices.push_back(ii(l, 1));
        indices.push_back(ii(r, -1));
    }

    sort(indices.begin(), indices.end());

    int current = 0, res = 0;

    for (ii &tmp : indices)
    {
        current += tmp.second;
        res = max(res, current);
    }

    cout << res;
}
