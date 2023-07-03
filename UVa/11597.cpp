#include <iostream>

using namespace std;

int main()
{
    int n, cnt = 1;
    while (cin >> n && n != 0)
    {
        cout << "Case " << cnt++ << ": " << n / 2 << '\n';
    }
}