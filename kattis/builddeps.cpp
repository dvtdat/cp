#include <bits/stdc++.h>
#define maxN 100010

using namespace std;

vector<int> adj[maxN];
bool mark[maxN];

int main()
{
    int n; cin >> n; cin.ignore();

    map<string, int> m;
    map<int, string> m2;
    vector<int> state(n + 1, 0);

    int idx = 0;

    for (int i = 0; i < n; ++i)
    {
        int u, v;
        char tmp[100];
        cin.getline(tmp, 12, ':');
        string s = tmp;

        if (!m[s])
        {
            //cout << s << endl;
            m[s] = ++idx;
            m2[idx] = s;
        }
        u = m[s];

        string tmp2;
        getline(cin, tmp2);
        stringstream ss(tmp2);
        string word;
        while (ss >> word)
        {
            if (!m[word])
            {
                //cout << word << endl;
                m[word] = ++idx;
                m2[idx] = word;
            }
            v = m[word];
            adj[v].push_back(u);
            state[u]++;
        }
    }

    string s; cin >> s; //cout << m[s];

    queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        if (state[i] == 0 && i != m[s]) q.push(i); //cout << i << endl;
    }

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for (int v : adj[u])
        {
            state[v]--;
            if (state[v] == 0 && v != m[s]) q.push(v);
        }
    }

    q.push(m[s]);
    while (!q.empty())
    {
        int u = q.front(); q.pop();

        cout << m2[u] << endl;

        for (int v : adj[u])
        {
            state[v]--;
            if (state[v] == 0) q.push(v);
        }
    }
}
