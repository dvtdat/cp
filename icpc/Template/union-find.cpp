/*
    Description: Basic Disjoint-set data structure with example.
    Complexity: O(a(N))
*/

#include <bits/stdc++.h>

using namespace std;

struct UnionFind
{
    vector<int> e;
    UnionFind(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

int main()
{
    int numPeople = 7; // Total number of people (A, B, C, D, E, F, G)
    UnionFind myUF(numPeople);

    // Simulate friendships
    myUF.join(0, 1); // A and B are friends
    myUF.join(1, 2); // B and C are friends
    myUF.join(3, 4); // D and E are friends
    myUF.join(5, 6); // F and G are friends

    // Queries
    cout << "Are A and C in the same friend group? " << (myUF.sameSet(0, 2) ? "Yes" : "No") << endl; // Should print "Yes"
    cout << "Are B and D in the same friend group? " << (myUF.sameSet(1, 3) ? "Yes" : "No") << endl; // Should print "No"

    // Calculate the size of each friend group
    cout << "Size of the friend group containing A: " << myUF.size(0) << endl; // Should print "3" (A, B, C)
    cout << "Size of the friend group containing D: " << myUF.size(3) << endl; // Should print "2" (D, E)

    return 0;
}