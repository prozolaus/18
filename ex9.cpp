#include "std_lib_facilities.h"

// static storage
int a = 0;
int b = 0;
int c = 0;

void print(const int *p1, const int *p2, const int *p3)
{
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << endl;
}

int main()
try
{
    // static storage
    int *pa = &a;
    int *pb = &b;
    int *pc = &c;
    print(pa, pb, pc);

    // stack
    int sa = 0;
    int sb = 0;
    int sc = 0;
    int *psa = &sa;
    int *psb = &sb;
    int *psc = &sc;
    print(psa, psb, psc);

    // free store / heap
    int *ha = new int(0);
    int *hb = new int(0);
    int *hc = new int(0);
    print(ha, hb, hc);

    // array on free store
    int *harr = new int[5];
    for (int i = 0; i < 5; ++i)
    {
        harr[i] = 0;
        cout << &harr[i] << "\n";
    }
    delete[] harr;
    delete hc;
    delete hb;
    delete ha;
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
