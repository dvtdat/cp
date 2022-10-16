#include <bits/stdc++.h>
#define maxN 400005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;

vector<int> indices;
ii query[maxN];
iii update[maxN];
ll diff[maxN], prefix[maxN], interval[maxN], width[maxN], value[maxN];

int compress(int x)
{
    return lower_bound(indices.begin(), indices.end(), x) - indices.begin();
}

int main()
{
    int n, q; cin >> n >> q;

    for (int i = 0; i < n; ++i)
    {
        int l, r, v; cin >> l >> r >> v;
        indices.push_back(l);
        indices.push_back(r);
        update[i] = iii(ii(l, r), v);
    }

    for (int i = 0; i < q; ++i)
    {
        int l, r; cin >> l >> r;
        indices.push_back(l);
        indices.push_back(r);
        query[i] = ii(l, r);
    }

    //sort and delete duplicate indices
    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());


    //compress and add +v to l, -v to r - 1
    for (int i = 0; i < n; ++i)
    {
        iii tmp = update[i];
        diff[compress(tmp.first.first) + 1] += tmp.second;
        diff[compress(tmp.first.second) + 1] -= tmp.second;
    }

    //measuring how wide is it between 2 indices
    for (int i = 1; i < indices.size(); ++i)
    {
        width[i] = indices[i] - indices[i - 1];
    }

    //prefix sum
    for (int i = 1; i < indices.size(); ++i)
    {
        value[i] = value[i - 1] + diff[i];
    }

    //prefix sum second time with the width
    for (int i = 1; i < indices.size(); ++i)
    {
        prefix[i] = prefix[i - 1] + value[i] * width[i];
    }

    for (int i = 0; i < q; ++i)
    {
        cout << prefix[compress(query[i].second)] - prefix[compress(query[i].first)] << '\n';
    }
}
