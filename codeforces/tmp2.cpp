#include <iostream>
#include <cstring>

void process(const char *a, char *outstr)
{
    char *str = (char*)a;
    int lenStr = strlen(str);

    int i = 0, j = lenStr;
    while (!('a' <= str[i] && str[i] <= 'z') && !('A' <= str[i] && str[i] <= 'Z')) i++;
    while (!('a' <= str[j] && str[j] <= 'z') && !('A' <= str[j] && str[j] <= 'Z')) j--;

    char *tmp = new char[j - i + 1];
    int cnt = 0, lenTmp = j - i + 1;

    for (int k = 0; k <= lenTmp; ++k) 
    {
        tmp[k] = a[k + i];
    }

    for (int k = i; k <= j; ++k)
    {
        if (!('a' <= tmp[k] && tmp[k] <= 'z') && !('A' <= tmp[k] && tmp[k] <= 'Z') && !(tmp[k] == ' ')) 
            cnt++;
    }

    str = new char[strlen(tmp) - cnt];
    lenStr = 0;

    for (int k = 0; k <= strlen(tmp); ++k)
    {
        if (('a' <= tmp[k] && tmp[k] <= 'z') || ('A' <= tmp[k] && tmp[k] <= 'Z') || (tmp[k] == ' '))
            str[lenStr++] = tmp[k]; 
        str[lenStr] = '\0';
    }

    bool flag = true;

    for (int k = 0; k <= strlen(str); ++k)
    {
        if (str[k] == ' ')
        {
            flag = true; continue;
        }
        if (flag)
        {
            if ('a' <= str[k] && str[k] <= 'z') str[k] = str[k] - 'a' + 'A';
            flag = false;
            continue;
        }
        
        if ('A' <= str[k] && str[k] <= 'Z') str[k] = str[k] - 'A' + 'a';
    }

    int outLen = 0;
    cnt = 0;
    
    for (int k = 0; k <= strlen(str); ++k)
    {
        if (('A' <= str[k] && str[k] <= 'Z' || ('a' <= str[k] && str[k] <= 'z'))) outLen++;
        if ('A' <= str[k] && str[k] <= 'Z') cnt++;
    }

    outstr = new char[outLen + cnt - 1];
    outstr[outLen + cnt - 1] = '\0';
    int n = 0;

    for (int k = 0; k <= strlen(str); ++k)
    {
        if ('A' <= str[k] && str[k] <= 'Z' && k != 0) outstr[n++] = ' ';
        if (str[k] != ' ') outstr[n++] = str[k];
    }

    std::cout << outstr << ' ';
}

int main()
{
    const char *a = " doan vie*(*((t tien 421dat  ";
    char *b;
    process(a, b);
} 