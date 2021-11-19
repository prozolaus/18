#include "std_lib_facilities.h"

char *strdup(const char *s)
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

int main()
try
{
    char s[] = "Hello, World!";
    char *s_copy = strdup(s);
    cout << s_copy << endl;
    delete[] s_copy;
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
