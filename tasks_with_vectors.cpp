#include "std_lib_facilities.h"

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void print_vector(const vector<int> &vec)
{
    const int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        cout << vec[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << endl;
}

void f(const vector<int> &mas)
{
    const int size = mas.size();
    vector<int> lv(size);
    for (int i = 0; i < size; i++)
        lv[i] = mas[i];
    print_vector(lv);
    vector<int> lv2 = mas;
    print_vector(lv2);
}

int main()
try
{
    f(gv);
    vector<int> vv;
    for (int i = 0, fact = 1; i < 10; i++)
    {
        fact = fact * (i + 1);
        vv.push_back(fact);
    }
    f(vv);
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
