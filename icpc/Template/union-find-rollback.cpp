/*
    Description: Disjoint-set with undo. If undo is not needed, skip st, time() and rollback().
    Complexity: O(log(N))
*/

#include <bits/stdc++.h>

using namespace std;

struct RollbackUF
{
    vector<int> e;
    vector<pair<int, int>> st;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return st.size(); }
    void rollback(int t)
    {
        for (int i = time(); i-- > t;) e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

int main()
{
    int numPeople = 7; // Total number of people (A, B, C, D, E, F, G)
    RollbackUF myUF(numPeople);

    // Simulate friendships
    myUF.join(0, 1); // A and B are friends
    myUF.join(1, 2); // B and C are friends
    myUF.join(3, 4); // D and E are friends
    myUF.join(5, 6); // F and G are friends

    // Queries
    cout << "Are A and C in the same friend group? " << (myUF.find(0) == myUF.find(2) ? "Yes" : "No") << endl; // Should print "Yes"
    cout << "Are B and D in the same friend group? " << (myUF.find(1) == myUF.find(3) ? "Yes" : "No") << endl; // Should print "No"

    // Calculate the size of each friend group
    cout << "Size of the friend group containing A: " << myUF.size(0) << endl; // Should print "3" (A, B, C)
    cout << "Size of the friend group containing D: " << myUF.size(3) << endl; // Should print "2" (D, E)

    // Perform a rollback
    int rollbackTime = myUF.time(); // Current time
    myUF.join(2, 3); // C and D become friends
    cout << "Are C and D in the same friend group after the new join? " << (myUF.find(2) == myUF.find(3) ? "Yes" : "No") << endl; // Should print "Yes"
    
    // Rollback to the previous state
    myUF.rollback(rollbackTime); // Rollback to the time before C and D became friends

    // Verify the state after rollback
    cout << "Are C and D in the same friend group after the rollback? " << (myUF.find(2) == myUF.find(3) ? "Yes" : "No") << endl; // Should print "No"

    return 0;
}
