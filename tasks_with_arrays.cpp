#include "std_lib_facilities.h"

const int len = 10;
int ga[len] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void print_array(const int mas[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << mas[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << endl;
}

void f(const int mas[], int size)
{
    int la[size];
    for (int i = 0; i < size; i++)
        la[i] = mas[i];
    print_array(la, size);

    int *p = new int[size];
    for (int i = 0; i < size; i++)
        p[i] = mas[i];
    print_array(p, size);
    delete[] p;
}

int main()
try
{
    f(ga, len);
    int aa[len];
    for (int i = 0, fact = 1; i < len; i++)
    {
        fact = fact * (i + 1);
        aa[i] = fact;
    }
    f(aa, len);
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
