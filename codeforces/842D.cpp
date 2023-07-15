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

const int LG = 18;

struct Trie
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
    }

    int query(int x)
    {
        // To find the maximum MEX, try to check whether the left subtree of a binary tree
        // is an unbalanced binary tree, prioritize finding it in the left subtree,
        // if not, move on to the right subtree.

        // If x[i] is 1, it is equal to the fact that the left and right subtree
        // is being swap to each other, we will try to check the left subtree
        // first if x[i] = 0, or check the right subtree first if x[i] = 1.

        Node* ptr = root;
        int res = 0;
        for (int i = LG; i >= 0; --i)
        {
            if (ptr == nullptr) break;
            
            int c = (x >> i) & 1;
            if (ptr->child[c] != nullptr && ptr->child[c]->cnt == (1 << i))
            {
                ptr = ptr->child[c ^ 1];
                res += (1 << i);
            }
            else ptr = ptr->child[c];
        }

        return res;
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    
    vector<int> a(n);
    Trie trie;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int i : a) trie.add(i);

    // Because of the associative property of XOR, Ai ^ x ^ y ^ z ^ ... = Ai ^ (x ^ y ^ z ^ ...)
    // we can save (x ^ y ^ z ^ ...) as cur
    int cur = 0;
    while (m--)
    {
        int x; cin >> x;
        cur = cur ^ x;
        cout << trie.query(cur) << '\n';
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

