//seven seas

#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int u, v; cin >> u >> v;

        if (u != v)
        {
            cout << "Happy Alex";
            return 0;
        }
    }

    cout << "Poor Alex";
}
