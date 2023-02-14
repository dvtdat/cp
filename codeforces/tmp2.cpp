#include <iostream>
#include <cstring>

using namespace std;

void printFirstRepeatedWord(char str[]) 
{
    char *words[100];
    int strLength = strlen(str);
    int numberOfWord = 0;

    int i = 0;
    while (i < strLength)
    {
        char *tmpstr = new char[100];
        int tmpstrLength = 0;
        
        while (str[i] != ' ' && i < strLength)
        {
            tmpstr[tmpstrLength++] = str[i++];
        }
        tmpstr[tmpstrLength] = '\0';
        words[numberOfWord++] = tmpstr;
        i++;
    }
    
    for (int i = 0; i < numberOfWord - 1; ++i)
    {
        for (int j = i + 1; j < numberOfWord; ++j)
        {
            if (!strcmp(words[i], words[j]))
            {
                cout << words[i]; return;
            }
        }
    }

    cout << "No Repetition";
}

int main()
{
    char str[] = "a b" ;
    printFirstRepeatedWord(str);
}