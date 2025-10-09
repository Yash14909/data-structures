/* 
Program 10
Consider the Single Linked List containing the following elements:
Roll no (int), sname (char[20]), city (char[20]), and course (char[3]).
Write a program in C++ to represent a Linked List with the above elements.
*/

#include <iostream.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h>
#include <ctype.h>

struct stud
{
    int rno;
    char sname[20];
    char city[20];
    char course[3];
    struct stud *link;
} *h, *p, *n, *c;

void main()
{
    char resp;
    h = p = c = n = NULL;
    clrscr();

    do
    {
        // Dynamic allocation of new node
        c = new stud;

        cout << "\nEnter the Roll No: ";
        cin >> c->rno;

        cout << "Enter the Name: ";
        cin >> c->sname;

        cout << "Enter the City: ";
        cin >> c->city;

        cout << "Enter the Course: ";
        cin >> c->course;

        c->link = NULL;

        if (h == NULL)
        {
            h = c;
            p = c;
        }
        else
        {
            p->link = c;
            p = c;
        }

        cout << "\nAny more additions (y/n)? ";
        resp = getche();

    } while (toupper(resp) == 'Y');

    cout << "\n\nLinked List is:\n";

    n = h;
    while (n != NULL)
    {
        cout << "\nRoll No   : " << n->rno;
        cout << "\nName      : " << n->sname;
        cout << "\nCity      : " << n->city;
        cout << "\nCourse    : " << n->course;
        cout << "\n---------------------------";
        n = n->link;
    }

    getch();
}

