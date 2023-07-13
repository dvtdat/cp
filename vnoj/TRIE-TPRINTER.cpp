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

string mxS = "";

struct Trie
{
    struct Node
    {
        Node* child[26];
        int exist;

        Node()
        {
            for (int i = 0; i < 26; ++i) child[i] = nullptr;
            exist = 0;
        }
    };

    int cur;
    Node* root;
    Trie() : cur(0)
    {
        root = new Node();
    }

    void add(string s)
    {
        Node* ptr = root;
        for (char f : s)
        {
            int c = f - 'a';
            if (ptr->child[c] == nullptr) ptr->child[c] = new Node();
            ptr = ptr->child[c];
        }
        ptr->exist++;
    }

    void dfs(Node* ptr, int depth, bool type, string &res)
    {
        for (int i = 0; i < ptr->exist; ++i) res += 'P';
        if (depth == mxS.size()) return;

        if (type)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (ptr->child[i] != nullptr && i != mxS[depth] - 'a')
                {
                    res += (char)(i + 'a');
                    dfs(ptr->child[i], depth + 1, 0, res);
                    res += '-';
                }
            }
            res += mxS[depth];
            dfs(ptr->child[mxS[depth] - 'a'], depth + 1, 1, res);
        }
        else
        {
            for (int i = 0; i < 26; ++i)
            {
                if (ptr->child[i] == nullptr) continue;
                res += (char)(i + 'a');
                dfs(ptr->child[i], depth + 1, 0, res);
                res += '-';
            }
        }
    }

    void dfs()
    {
        string res = "";
        dfs(root, 0, 1, res);

        cout << res.size() << '\n';
        cout << res << '\n';
    }
};

void solve()
{
    int n; cin >> n;

    Trie trie;

    for (int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        trie.add(s);
        if (s.size() > mxS.size()) mxS = s;
    }

    trie.dfs();
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

