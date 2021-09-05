#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l, n;
    while (cin >> l >> n)
    {
        vector<int> a, left, right;
        int r = 0;

        for (int i = 0; i < n; ++i)
        {
            char c; int t; cin >> t >> c;
            if (c == 'R') right.push_back(l - t), r++;
            else left.push_back(t);
            a.push_back(t);
        }

        sort(a.begin(), a.end());
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        if (left.size() > 0 && (right.size() == 0 || left[left.size() - 1] > right[right.size() - 1]))
        {
            cout << "The last ant will fall down in " << left[left.size() - 1] << " seconds - started at " << a[n - r - 1] << "." << endl;
        }
        else if (right.size() > 0 && (left.size() == 0 || left[left.size() - 1] < right[right.size() - 1]))
        {
            cout << "The last ant will fall down in " << right[right.size() - 1] << " seconds - started at " << a[n - r] << "." << endl;
        }
        else
        {
            cout << "The last ant will fall down in " << right[right.size() - 1] << " seconds - started at ";
            cout << min(a[n - r], a[n - r - 1]) << " and " << max(a[n - r], a[n - r - 1]) << "."<<endl;
        }
    }
}
