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

struct Node {
public:
    int data;
    int size;
    int exp;
    Node* last;
    Node* next;
    Node(int data, Node* next = nullptr) : data(data), next(next), last(this), size(1), exp(0) {};
};

void append(Node* &head1, Node* &head2)
{
    if (head1 == nullptr || head2 == nullptr) return;
    head1->last->next = head2;
    head1->last = head2->last;
    head1->size += head2->size;
}

int get(int a, const vector<int> &par, vector<int> &exp)
{
    if (par[a] == a) return exp[a];
    return exp[a] + get(par[a], par, exp);
}

void add(int &a, int val, vector<int> &root, vector<int> &exp)
{
    exp[root[a]] += val;
}

void unite(int &a, int &b, vector<int> &root, vector<int> &par, vector<Node*> &list, vector<int> &exp)
{
    a = root[a];
    b = root[b];

    if (a == b) return;     // IMPORTANT

    if (list[a]->size > list[b]->size) swap(a, b);
    Node* ptr = list[a];
    while (ptr != nullptr)
    {
        root[ptr->data] = b;
        ptr = ptr->next;
    }

    par[a] = b;
    exp[a] -= exp[b];
    append(list[b], list[a]);
};

void solve()
{
    int n, q; cin >> n >> q;
    
    vector<int> root(n + 1);
    vector<int> par(n + 1);
    vector<int> exp(n + 1, 0);
    vector<Node*> list(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        root[i] = par[i] = i;
        list[i] = new Node(i);
    }

    string order;
    for (int i = 0; i < q; ++i)
    {
        int u, v;
        cin >> order;
        if (order == "join")
        {
            cin >> u >> v;
            unite(u, v, root, par, list, exp);
        }

        if (order == "add")
        {
            cin >> u >> v;
            add(u, v, root, exp);
        }

        if (order == "get")
        {
            cin >> u;
            cout << get(u, par, exp) << '\n';
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
