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

    bool find(int x)
    {
        Node* ptr = root;
        for (int i = LG; i >= 0; --i)
        {
            int c = (x & (1 << i) ? 1 : 0);
            if (ptr->child[c] == nullptr) return false;
            ptr = ptr->child[c];
        }
        return (ptr->exist);
    }

    void remove(int x)
    {
        if (!find(x)) return;
        Node* ptr = root;
        for (int i = LG; i >= 0; --i)
        {
            int c = (x >> i) & 1;
            Node* tmp = ptr->child[c];
            tmp->cnt--;
            if (tmp->cnt == 0)
            {
                ptr->child[c] = nullptr;
                return;
            }
            ptr = tmp;
        }
        ptr->exist--;
    }

    ll query(int x)
    {
        Node* ptr = root;
        ll res = 0;
        for (int i = LG; i >= 0; --i)
        {
            if (ptr == nullptr) break;

            int c = (x >> i) & 1;
            if (ptr->child[c] != nullptr)
            {
                ptr = ptr->child[c];
            }
            else
            {
                ptr = ptr->child[c ^ 1];
                res += (1LL << i);
            }
        }

        remove(res ^ x); // O(2logN)

        return res;
    }
};

void solve()
{
    int n; cin >> n;
    
    vector<int> a(n), p(n);
    Trie trie;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
        trie.add(p[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << trie.query(a[i]) << ' ';
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

