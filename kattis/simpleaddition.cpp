#include <bits/stdc++.h>

using namespace std;

string add(string x,string y)
{
    int mem = 0, t = 0;
    string ans="";

    int lmx = max(x.size(), y.size());
    for(int i = x.size(); i < lmx; i++) x = "0" + x;
    for(int i = y.size(); i < lmx; i++) y = "0" + y;

    for(int i = lmx - 1;i >= 0; i--){
        t=(x[i] - 48) + (y[i] - 48) + mem;
        mem = (t > 9);
        ans = char(t % 10 + 48) + ans;
    }
    if (mem) ans = "1" + ans;
    return ans;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << add(a, b);
}

