/* 
Program 5
Consider two single dimensional arrays of size 20 and 3 respectively.
Write a program in C++ to display all the elements which are common in both arrays.
*/

#include <iostream.h>
#include <conio.h>
#define mx 20

void main()
{
    int i, j, n1, n2, m1[mx], m2[mx];
    clrscr();

    cout << "Enter number of elements for Array 1: ";
    cin >> n1;

    cout << "Enter elements of Array 1:\n";
    for (i = 0; i < n1; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> m1[i];
    }

    cout << "\nEnter number of elements for Array 2: ";
    cin >> n2;

    cout << "Enter elements of Array 2:\n";
    for (i = 0; i < n2; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> m2[i];
    }

    cout << "\nCommon elements are:\n";

    int found = 0;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (m1[i] == m2[j])
            {
                cout << m1[i] << "\t";
                found = 1;
            }
        }
    }

    if (found == 0)
        cout << "No common elements found.";

    getch();
}
