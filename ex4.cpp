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

const char *findx(const char *s, const char *x)
{
    if (s == nullptr || x == nullptr)
        error("nullptr was sent to findx()");

    const char *ptr = nullptr;
    int count = 0;

    while (*s)
        if (*x == *s++)
        {
            ptr = s - 1;
            while (*(++x))
            {
                count++;
                if (*x != *s++)
                //wrong occurrence
                {
                    ptr = nullptr;
                    s -= count; //return pointer s back to the first position
                    x -= count; //return pointer x back to the first position
                    count = 0;
                    break; //continue the searching
                }
            }
            if (ptr)
                return ptr; //first occurrence
        }
    return nullptr; //nothing found
}

const char *findx(const char *s, const char *x, int ns, int nx)
{
    if (s == nullptr || x == nullptr)
        error("nullptr was sent to findx()");

    const char *ptr = nullptr;
    char *s1 = mystrdup(s, ns), *s2 = mystrdup(x, nx), *ps1 = s1, *ps2 = s2;
    int count1 = 0, count2 = 0;

    while (*s1)
    {
        count1++;
        if (*s2 == *s1++)
        {
            ptr = s + count1 - 1;
            while (*(++s2))
            {
                count2++;
                if (*s2 != *s1++)
                {
                    ptr = nullptr;
                    s1 -= count2;
                    s2 -= count2;
                    count2 = 0;
                    break;
                }
            }
            if (ptr)
                break;
        }
    }
    delete[] ps1;
    delete[] ps2;
    return ptr;
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

void print_str(const char *s)
{
    if (!s)
        error("Cannot print from nullptr");
    cout << s << endl;
}

void test_strdup1()
{
    char *s1 = new char[3];
    s1[0] = 'a';
    s1[1] = 'b';
    s1[2] = 'c';
    char *s2 = new char[2];
    s2[0] = 'a';
    s2[1] = 'b';

    char *ptr1 = mystrdup(s1);
    char *ptr2 = mystrdup(s2);

    print_str(s1);
    print_str(s2);
    print_str(ptr1);
    print_str(ptr2);

    delete[] s1;
    delete[] s2;
    delete[] ptr1;
    delete[] ptr2;
}

void test_strdup2()
//catastrophe
{
    char s1[] = {'a', 'b', 'c'};
    char s2[] = {'a', 'b'};
    char *ptr1 = mystrdup(s1);
    char *ptr2 = mystrdup(s2);

    print_str(s1);
    print_str(s2);
    print_str(ptr1);
    print_str(ptr2);

    delete[] ptr1;
    delete[] ptr2;
}

void test_strdup3()
// test1_1 fixed version
{
    char s1[] = {'a', 'b', 'c'};
    char s2[] = {'a', 'b'};

    const int n1 = 3, n2 = 2;

    char *ptr1 = mystrdup(s1, n1);
    char *ptr2 = mystrdup(s2, n2);

    print_str(s1);
    print_str(s2);
    print_str(ptr1);
    print_str(ptr2);

    delete[] ptr1;
    delete[] ptr2;
}

void test_findx1()
{
    char *s1 = new char[3];
    s1[0] = 'a';
    s1[1] = 'b';
    s1[2] = 'c';
    char *s2 = new char[2];
    s2[0] = 'b';
    s2[1] = 'c';

    const char *ptr = findx(s1, s2);

    print_str(ptr);

    delete[] s1;
    delete[] s2;
}

void test_findx2()
//catastrophe
{
    char s1[] = {'a', 'b', 'c'};
    char s2[] = {'b', 'c'};

    const char *ptr = findx(s1, s2);

    print_str(ptr);
}

void test_findx3()
{
    char s1[] = {'a', 'b', 'c'};
    char s2[] = {'b', 'c'};
    const int n1 = 3, n2 = 2;

    const char *ptr = findx(s1, s2, n1, n2);

    print_str(ptr);
}

void test_strcmp1()
{
    char *s1 = new char[3];
    s1[0] = 'a';
    s1[1] = 'b';
    s1[2] = 'c';
    char *s2 = new char[2];
    s2[0] = 'b';
    s2[1] = 'c';

    cout << mystrcmp(s1, s2) << endl;

    delete[] s1;
    delete[] s2;
}

void test_strcmp2()
{
    char s1[] = {'a', 'b', 'c'};
    char s2[] = {'b', 'c'};

    cout << mystrcmp(s1, s2) << endl;
}

int main()
try
{
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
