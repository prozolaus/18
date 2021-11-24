#include "std_lib_facilities.h"

bool is_palindrome(const string &s)
{
    int n = s.length();
    string revs;
    while (n--)
        revs.push_back(s[n]);
    return s == revs;
}

int main()
try
{
    const string s = "malayalam";
    cout << s << " is";
    if (!is_palindrome(s))
        cout << " not";
    cout << " a palindrome.\n";
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
