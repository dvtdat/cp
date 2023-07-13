//

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

const int LG = 22;

struct BinTrie
{
    struct Node
    {
        Node* child[2];
        int cnt;

        Node(): cnt(0)
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
            ptr->cnt++;
        }
    }

    ll get(int prefix, int k)
    {
        ll tmp = 0;
        Node* ptr = root;

        for (int i = LG; i >= 0; --i)
        {
            if (ptr == nullptr) break;

            int pBit = (prefix >> i) & 1;
            int kBit = (k >> i) & 1;

            if (pBit == kBit)
            {
                if (pBit == 1) tmp += (ptr->child[1] != nullptr ? ptr->child[1]->cnt : 0);
                ptr = ptr->child[0];
            }
            else
            {
                if (pBit == 0) tmp += (ptr->child[0] != nullptr ? ptr->child[0]->cnt : 0);
                ptr = ptr->child[1];                
            }
        }

        return tmp;
    }
};

void solve()
{
    int n, k; cin >> n >> k;
    
    vector<int> a(n + 1);
    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll res = 0;
    BinTrie trie;

    for (int i = 1; i <= n; ++i)
    {
        prefix[i] = prefix[i - 1] ^ a[i];
        res += trie.get(prefix[i], k);
        trie.add(prefix[i]);
    }
    res += trie.get(0, k);

    cout << res << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
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

