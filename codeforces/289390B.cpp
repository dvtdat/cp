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
    int minVal, maxVal;
    Node* last;
    Node* next;
    Node(int data, Node* next = nullptr)
    {
        this->data = data;
        this->next = next;
        this->last = this;
        this->size = 1;
        this->minVal = data;
        this->maxVal = data;
    }
};

void append(Node* &head1, Node* &head2)
{
    if (head1 == nullptr || head2 == nullptr) return;
    head1->last->next = head2;
    head1->last = head2->last;

    head1->size += head2->size;
    head1->minVal = min(head1->minVal, head2->minVal);
    head1->maxVal = max(head1->maxVal, head2->maxVal);
}

void get(int a, const vector<int> &par, vector<Node*> &list)
{
    cout << list[par[a]]->minVal << ' ';
    cout << list[par[a]]->maxVal << ' ';
    cout << list[par[a]]->size << '\n';
}

void unite(int &a, int &b, vector<int> &par, vector<Node*> &list)
{
    a = par[a];
    b = par[b];

    if (a == b) return;     // IMPORTANT

    if (list[a]->size > list[b]->size) swap(a, b);
    Node* ptr = list[a];
    while (ptr != nullptr)
    {
        par[ptr->data] = b;
        ptr = ptr->next;
    }
    append(list[b], list[a]);
};

void solve()
{
    int n, q; cin >> n >> q;
    
    vector<int> par(n + 1);
    vector<Node*> list(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        par[i] = i;
        list[i] = new Node(i);
    }

    string order;
    for (int i = 0; i < q; ++i)
    {
        int u, v;
        cin >> order;
        if (order == "union")
        {
            cin >> u >> v;
            unite(u, v, par, list);
        }
        else
        {
            cin >> u;
            get(u, par, list);
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

