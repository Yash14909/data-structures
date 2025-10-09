/* 
Program 7
Write a menu-driven program for stack containing the following functions:
* PUSH
* POP
* DISPLAY
* PEEK
*/

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#define mx 10

int stk[mx];
int top = -1;
int stackempty = 1, stackfull = 0;

void push(int);
int pop(void);
int printmenu(void);
void display(void);

void main()
{
    int puc, poc, resp, resp1, ch;

    do
    {
        clrscr();
        ch = printmenu();

        switch (ch)
        {
        case 1:
            do
            {
                cout << "\nEnter the number: ";
                cin >> puc;
                push(puc);
                cout << "\nAny more additions (y/n)? ";
                resp1 = getche();
            } while (toupper(resp1) == 'Y');
            break;

        case 2:
            if (stackempty == 1)
                cout << "\nStack is empty!";
            else
            {
                poc = pop();
                cout << "\nPopped element: " << poc;
            }
            break;

        case 3:
            if (stackempty == 1)
                cout << "\nStack is empty!";
            else
                cout << "\nTop (peeked) element: " << stk[top];
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            cout << "\nInvalid choice!";
        }

        cout << "\n\nAny more trials (y/n)? ";
        resp = getche();

    } while (toupper(resp) == 'Y');
}

// Function to push an element
void push(int puc)
{
    if (top == mx - 1)
    {
        cout << "\nStack is full!";
        getch();
        return;
    }

    ++top;
    stk[top] = puc;
    stackempty = 0;

    if (top == mx - 1)
        stackfull = 1;
}

// Function to pop an element
int pop(void)
{
    int poc;

    if (stackempty == 1)
    {
        cout << "\nStack is empty!";
        getch();
        return -1;
    }

    poc = stk[top];
    top--;

    if (top == -1)
        stackempty = 1;

    return (poc);
}

// Function to display the stack
void display(void)
{
    if (stackempty == 1)
    {
        cout << "\nStack is empty!";
        return;
    }

    cout << "\nStack elements (top to bottom):\n";
    for (int i = top; i >= 0; i--)
        cout << stk[i] << "\t";
}

// Function to print menu
int printmenu(void)
{
    int ch;
    cout << "\n\nM E N U\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> ch;
    return (ch);
}
