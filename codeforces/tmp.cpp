#include <iostream>
#include <cstring>

using namespace std;

void process(const char str[], char outstr[])
{
    int tmpstrLength = 0, strLength = strlen(str), outstrLength = 0;
    char tmpstr[100];

    // Delete those character that is neither in abcABC or a spacebar
    for (int i = 0; i < strLength; ++i)
    {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z') || (str[i] == ' '))
            tmpstr[tmpstrLength++] = str[i];
    }
    tmpstr[tmpstrLength] = '\0';

    // Delete excess spacebars
    bool flag = false;
    int i = 0;
    while (i < tmpstrLength)
    {
        while (tmpstr[i] == ' ') i++;
        if (flag && tmpstr[i - 1] == ' ') outstr[outstrLength++] = ' ';
        else flag = true;

        outstr[outstrLength++] = tmpstr[i++];
    }
    outstr[outstrLength] = '\0';

    // Uppercase and lowercase management
    for (int i = 0; i < outstrLength; ++i)
    {
        if ((i == 0 || outstr[i - 1] == ' ') && ('a' <= outstr[i] && outstr[i] <= 'z')) 
            outstr[i] = outstr[i] - 'a' + 'A';

        if ((i != 0 && outstr[i - 1] != ' ') && ('A' <= outstr[i] && outstr[i] <= 'Z'))
            outstr[i] = outstr[i] - 'A' + 'a';
    }
}

int main()
{
    const int MAX_SIZE = 100;
    char str[] = " doan VAN *(()hau @!#$" ;
    char outstr[MAX_SIZE];
    process(str, outstr);
    cout << outstr;
}