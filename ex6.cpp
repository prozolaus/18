#include "std_lib_facilities.h"

string cat_dot(const string &s1, const string &s2, const string &separator = ".")
{
    return s1 + separator + s2;
}

int main()
try
{
    string str1 = cat_dot("James", "Hetfield");
    string str2 = cat_dot("James", "Hetfield", "_");
    cout << str1 << endl;
    cout << str2 << endl;
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
