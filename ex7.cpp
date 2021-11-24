#include "std_lib_facilities.h"

char *mystrdup(const char *s, int n)
{
    if (s == nullptr)
        error("nullptr was sent to strdup(char*)");

    if (n < 1)
        error("Empty string!");

    char *str = new char[n];
    for (int i = 0; i < n; i++)
        *(str + i) = *(s + i);

    return str;
}

char *cat_dot(const char *s1, const char *s2, int n1, int n2, const char separator = '.')
{
    char *str = new char[n1 + n2 + 1],
         *p = str,
         *ptr1 = mystrdup(s1, n1),
         *ptr2 = mystrdup(s2, n2);

    for (int i = 0; i < n1; i++)
        *p++ = ptr1[i];
    *p++ = separator;
    for (int i = 0; i < n2; i++)
        *p++ = ptr2[i];

    delete[] ptr1;
    delete[] ptr2;

    return str;
}

void print_str(const char *s)
{
    if (!s)
        error("Cannot print from nullptr");
    cout << s << endl;
}

void test1()
{
    char first_name[] = "James";
    char last_name[] = "Hetfield";
    int len1 = 5, len2 = 8;
    char *str = cat_dot(first_name, last_name, len1, len2, '_');
    print_str(str);
    delete[] str;
}

void test2()
{
    char first_name[] = {'J', 'a', 'm', 'e', 's'};
    char last_name[] = {'H', 'e', 't', 'f', 'i', 'e', 'l', 'd'};
    int len1 = 5, len2 = 8;
    char *str = cat_dot(first_name, last_name, len1, len2);
    print_str(str);
    delete[] str;
}

void test3()
{
    int len1 = 5, len2 = 8;
    char *first_name = new char[len1];
    first_name[0] = 'J';
    first_name[1] = 'a';
    first_name[2] = 'm';
    first_name[3] = 'e';
    first_name[4] = 's';
    char *last_name = new char[len2];
    last_name[0] = 'H';
    last_name[1] = 'e';
    last_name[2] = 't';
    last_name[3] = 'f';
    last_name[4] = 'i';
    last_name[5] = 'e';
    last_name[6] = 'l';
    last_name[7] = 'd';

    char sep = ' ';
    char *str = cat_dot(first_name, last_name, len1, len2, sep);
    print_str(str);

    delete[] str;
    delete[] first_name;
    delete[] last_name;
}

int main()
try
{
    test1();
    test2();
    test3();
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
