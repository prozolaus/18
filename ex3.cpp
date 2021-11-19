#include "std_lib_facilities.h"

char *mystrdup(const char *s)
{
    if (s == nullptr)
        error("nullptr was sent to strdup(char*)");

    int n = 0;
    while (*s)
    {
        n++;
        s++;
    }
    if (!n)
        error("Empty string!");

    char *str = new char[n];
    for (int i = 0; i < n; i++)
        *(str + i) = *(s - n + i);

    return str;
}

void to_lower(char *s)
{
    if (s == nullptr)
        error("Nullptr in to_lower(char*)!");
    while (*s)
    {
        if (*s >= 65 && *s <= 90) //from ASCII table from A to Z (65...90)
            *s += 32;             //a = A+32 (where A==65) etc.
        s++;
    }
}

int mystrcmp(const char *s1, const char *s2)
{
    char *str1 = mystrdup(s1), *p1 = str1;
    char *str2 = mystrdup(s2), *p2 = str2;
    to_lower(p1);
    to_lower(p2);

    do
    {
        if (*p1 == 0 && *p2 == 0)
            break;
        else if (*p1 == 0 || *p1 < *p2)
            return -1;
        else if (*p2 == 0 || *p1 > *p2)
            return 1;
    } while (*p1++ == *p2++);

    delete[] str1;
    delete[] str2;
    return 0;
}

int main()
try
{
    char s1[] = "Abc";
    char s2[] = "Abcd";
    cout << mystrcmp(s1, s2) << endl;
}
catch (const std::exception &e)
{
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Some kind of exception\n";
    return 2;
}