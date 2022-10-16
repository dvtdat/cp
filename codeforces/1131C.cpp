// rang' len

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);

    for (int &i : a) cin >> i;

    deque<int> q;

    sort(a.begin(), a.end());

    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 != 0) q.push_back(a[i - 1]);
        else q.push_front(a[i - 1]);
    }

    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop_front();
    }
}
