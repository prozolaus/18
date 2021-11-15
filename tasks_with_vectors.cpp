#include "std_lib_facilities.h"

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> mas, int size)
{
    vector<int> lv(size);
    for (int i = 0; i < size; i++)
    {
        lv[i] = mas[i];
        cout << lv[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << endl;

    vector<int> lv2 = mas;
    for (int i = 0; i < size; i++)
    {
        cout << lv2[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << endl;
}

int main()
try
{
    const int len = gv.size();
    f(gv, len);
    vector<int> vv;
    for (int i = 0, fact = 1; i < len; i++)
    {
        fact = fact * (i + 1);
        vv.push_back(fact);
    }
    f(vv, len);
    
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
