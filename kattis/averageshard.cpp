#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        int n, m;
        cin >> n >> m;
        vector<double> a(n);

        double _a = 0.0, _b = 0.0, tmp;


        for (int i = 0; i < n; ++i)
        {
            cin >> tmp;
            a.push_back(tmp);
            _a += tmp * 1.0 / n;
        }

        for (int i = 0; i < m; ++i)
        {
            cin >> tmp;
            _b += tmp * 1.0 / m;
        }

        int res = 0;
        for (double i : a)
        {
            if (i < _a && i > _b) res++;
        }

        cout << res << endl;
    }
}
