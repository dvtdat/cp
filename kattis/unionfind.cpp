#include <bits/stdc++.h>

using namespace std;

int par[1000100];

void readint(int& ret)
{
    ret = 0;
    char r;
    bool start = false, neg = false;
    while(true)
    {
        r = getchar();
        if ((r - '0' < 0 || r - '0' > 9) && r != '-' && !start) continue;

        if ((r - '0' < 0 || r - '0' > 9) && r != '-' && start) break;
        if (start) ret *= 10;
        start = true;
        if(r == '-') neg = true;
        else ret += r - '0';
    }
    if (neg) ret *= -1;
}

int anc(int p)
{
    return par[p] < 0 ? p : (par[p] = anc(par[p]));
}

void join(int p, int q)
{
    if ((p = anc(p)) == (q = anc(q))) return;
    if (par[q] < par[p]) swap(p, q);
    par[p] += par[q];
    par[q] = p;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q;
    readint(n);
    readint(q);
    for (int i = 0; i < n; ++i) par[i] = -1;

    while (q--)
    {
        char c; int u, v;
        c = getchar();
        readint(u);
        readint(v);

        if (c == '?') cout << (anc(u) == anc(v) ? "yes" : "no") << endl;
        else join(u, v);
    }
}
