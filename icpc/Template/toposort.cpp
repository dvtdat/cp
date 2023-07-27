/*
    Description: Topological sorting. Given is an oriented graph. Output is an
    ordering of vertices, such that there are edges only from left to right. If there
    are cycles, the returned list will have size smaller than n – nodes reachable
    from cycles will not be returned.
    Complexity: O(V + E)
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> topoSort(const vector<vector<int>> &adj)
{
    vector<int> indeg(adj.size()), ret;
    for (auto &li : adj)
    {
        for (int x : li) indeg[x]++;
    }

    queue<int> q; // or use priority_queue for lexic. largest ans
    for (int i = 0; i < adj.size(); ++i)
    {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty())
    {
        int i = q.front(); // or q.top() for priority_queue
        q.pop();

        ret.push_back(i);
        for (int x : adj[i])
        {
            if (--indeg[x] == 0) q.push(x);
        }
    }

    return ret;
}

int main()
{
    vector<vector<int>> graph = 
    {
        {1, 2}, // 0 points to 1 and 2
        {3},    // 1 points to 3
        {},     // 2 has no outgoing edges
        {4},    // 3 points to 4
        {}      // 4 has no outgoing edges
    };

    vector<int> result = topoSort(graph);

    cout << "Topological Sort Order:" << endl;
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
