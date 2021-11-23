#include "std_lib_facilities.h"

string cat_dot(const string &s1, const string &s2)
{
    return s1 + "." + s2;
}

int main()
try
{
    string str = cat_dot("James", "Hetfield");
    cout << str << endl;
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
