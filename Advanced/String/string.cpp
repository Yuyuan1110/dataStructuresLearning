#include <iostream>
using namespace std;

int main()
{
    char s[10] = "abcde";

    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = s[i] - 32;
        cout << s[i] << endl;
    }

    return 0;
}