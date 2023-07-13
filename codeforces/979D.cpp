// 
// https://vnoi.info/wiki/algo/data-structures/trie.md

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 1e9 + 7;
const int maxN = 100010;
const ll MOD = 998244353;
const double eps = 1e-12;

const int N = 50010;
const int LG = 18;

struct BinTrie
{
    struct Node
    {
        Node* child[2];
        int mn;

        Node(): mn(inf)
        {
            child[0] = child[1] = nullptr;
        }
    };

    int cur;
    Node* root;

    BinTrie(): cur(0)
    {
        root = new Node();
    }

    void add(int x)
    {
        Node* ptr = root;
        for (int i = LG; i >= 0; --i)
        {
            int c = (x >> i) & 1;
            if (ptr->child[c] == nullptr) ptr->child[c] = new Node();
            ptr = ptr->child[c];
            ptr->mn = min(ptr->mn, x);
        }
    }

    int query(int x, int bound)
    {
        Node* ptr = root;
        int res = 0;
        for (int i = LG; i >= 0; --i)
        {
            int c = (x >> i) & 1;

            // finding the largest (ai XOR x) number: prioritize the next node from the next c ^ 1 edge ((bin)x[i] = c)
            // always make sure the nodes and its value is in bound = s - x to suit the condition x + v < s

            if (ptr->child[c ^ 1] != nullptr && ptr->child[c ^ 1]->mn <= bound)
            {
                res += ((c ^ 1) << i);
                ptr = ptr->child[c ^ 1];
            }
            else
            {
                if (ptr->child[c] == nullptr || ptr->child[c]->mn > bound) return -1;
                ptr = ptr->child[c];
                res += (c << i);
            }
        }

        return res;
    }
};

BinTrie tries[maxN];
vector<int> d[maxN];

void solve()
{
    // making all possible tries for k: query only checking those number that k can divide
    for (int i = 1; i < maxN; ++i)
    {
        for (int j = i; j < maxN; j += i) d[j].push_back(i);
    }

    int q; cin >> q;
    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int u; cin >> u;
            for (int v : d[u]) tries[v].add(u);
        }
        else
        {
            int x, k, s; cin >> x >> k >> s;
            if (x % k != 0) cout << -1 << '\n';
            else cout << tries[k].query(x, s - x) << '\n';
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test = 1; //cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//

