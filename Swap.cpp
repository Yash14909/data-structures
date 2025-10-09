// Pctl - 15:
//Simple code

#include <iostream>
using namespace std;

template <class T>
void mySwap(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

int main()
{

    int i = 10, j = 20;
    cout << "\ni = " << i << "\nj = " << j << endl;
    cout << "\nAfter swapping" << endl;
    mySwap(i, j);
    cout << "\ni = " << i << "\nj = " << j << endl;

    cout << "\nNew Entry...." << endl;
    char ch = 'A', dh = 'Z';
    cout << "\nch = " << ch << "\ndh = " << dh << endl;
    cout << "\nAfter swapping" << endl;
    mySwap(ch, dh);
    cout << "\nch = " << ch << "\ndh = " << dh << endl;

    return 0;
}
