#include "std_lib_facilities.h"

char *mydoublestrdup(const char *s, int n)
{
    if (s == nullptr)
        error("nullptr was sent to strdup(char*)");

    if (n < 1)
        error("Empty string!");

    char *str = new char[n * 2 + 1];
    for (int i = 0; i < n; i++)
        *(str + i) = *(s + i);

    return str;
}

bool is_palindrome(const char s[], int n)
{
    int first = 0;
    int last = n - 1;
    while (first < last)
    {
        if (s[first] != s[last])
            return false;
        first++;
        last--;
    }
    return true;
}

istream &read_word(istream &is, char *buffer, int max)
{
    is.width(max);
    is >> buffer;
    if (strlen(buffer) == max - 1)
    {
        cout << "Input breaks after " << max - 1 << " characters!\n";
        char ch;
        while (is.get(ch))
            if (ch == '\n')
                break;
    }
    return is;
}

istream &read_word(istream &is, char *&buffer)
{
    long max = 100;
    char *ptr = new char[max + 1];
    char ch;
    is.width(max + 1);
    is >> ptr;
    while (strlen(ptr) == max)
    {
        char *ptr2 = mydoublestrdup(ptr, max); //new array with double size
        delete[] ptr;
        long i = max;
        max *= 2;
        while (i < max && is.get(ch))
        {
            if (ch == '\n')
                break;
            ptr2[i++] = ch;
            ptr2[i] = 0;
        }
        ptr = ptr2;
    }
    buffer = ptr;
    return is;
}

int main()
try
{
    /*
    constexpr int max = 5;
    for (char s[max]; read_word(cin, s, max);)
    {
        cout << s << " is";
        if (!is_palindrome(s, strlen(s)))
            cout << " not";
        cout << " a palindrome\n";
    }
    */

    char *s = nullptr;
    for (; read_word(cin, s);)
    {
        cout << s << " is";
        if (!is_palindrome(s, strlen(s)))
            cout << " not";
        cout << " a palindrome\n";
        delete[] s;
    }
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
