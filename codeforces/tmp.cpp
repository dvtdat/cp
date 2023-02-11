#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "hello tien dat";

    string newString = s.substr(6, s.length() - 6);

    cout << newString << ' ';
}