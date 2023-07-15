// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

const int LG = 31;

struct Trie
{
    struct Node
    {
        Node* child[2];
        int exist, cnt;

        Node(): exist(0), cnt(0)
        {
            child[0] = child[1] = nullptr;
        }
    };

    int cur;
    Node* root;

    Trie(): cur(0)
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
        ptr->exist++;
    }

    ll query(int prefix, int k)
    {
        Node* ptr = root;
        ll res = 0;
        ll cur = 0;

        for (int i = LG; i >= 0; --i)
        {
            if (ptr == nullptr) break;
            int c = (prefix >> i) & 1;

            if ((cur | (1LL << i)) >= k)
            {
                res += (ptr->child[c ^ 1] != nullptr ? ptr->child[c ^ 1]->cnt : 0);
                ptr = ptr->child[c];
            }
            else
            {
                cur |= (1LL << i);
                ptr = ptr->child[c ^ 1];
            }
        }

        if (cur >= k) res += (ptr != nullptr ? ptr->cnt : 0);

        return res;
    }
};

void solve()
{
    int n, k; cin >> n >> k;
    
    vector<int> a(n + 1), prefix(n + 1, 0);
    Trie trie;
    trie.add(0);

    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        prefix[i] = prefix[i - 1] ^ a[i];
        cnt += trie.query(prefix[i], k);
        trie.add(prefix[i]);
    }
    cout << cnt << '\n';
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

