/* 
Program 15
Write a program to traverse the graph using DFS method.
*/

#include <iostream.h>
#include <conio.h>
#include <alloc.h>
#include <ctype.h>

struct graph
{
    int node;
    struct graph *down;
    struct graph *next;
};

struct graph *start, *p, *q, *r, *s;
int stack[10], visit[10], tos = 0, count;

// Function to push node onto stack
void push(int x)
{
    stack[tos] = x;
    tos++;
    if (visit[x] == 0)
    {
        visit[x] = 1;
        count++;
    }
}

// Function to pop node from stack
int pop()
{
    int y;
    tos--;
    y = stack[tos];
    return (y);
}

// Function to print the graph
void print()
{
    p = q = start;
    cout << "\nYour graph is:\n";

    while (p != NULL)
    {
        cout << "\nParent Node " << p->node << " -> ";
        q = p->next;

        while (q != NULL)
        {
            cout << q->node << " ";
            q = q->next;
        }
        p = p->down;
    }
}

// DFS Traversal Function
void dfs()
{
    int is, parent, flag;
    r = p = q = s = start;

    cout << "\n\nEnter the initial node: ";
    cin >> is;

    cout << "\nDFS Traversal: " << is << " ";
    push(is);

    while (tos != 1)
    {
        flag = 0;
        parent = pop();
        p = start;

        while (p != NULL)
        {
            if (p->node == parent)
            {
                q = p->next;

                while (q != NULL)
                {
                    if (visit[q->node] == 0)
                    {
                        cout << q->node << " ";
                        push(p->node);
                        push(q->node);
                        flag = 1;
                        break;
                    }
                    else
                        q = q->next;
                }
            }

            if (flag == 1)
                break;
            else
                p = p->down;
        }
    }

    cout << "\nTraversal Completed.\n";
}

// Function to create a graph node
struct graph *create()
{
    struct graph *f;
    f = (struct graph *)malloc(sizeof(struct graph));
    f->next = NULL;
    f->down = NULL;
    cin >> f->node;
    return (f);
}

// Main Function
void main()
{
    int no;
    char ch;
    clrscr();
    count = 0;
    start = NULL;

    cout << "Enter the graph structure for DFS traversal:\n";

    do
    {
        cout << "\nEnter a parent node: ";
        p = create();

        if (start == NULL)
        {
            start = p;
            r = q = p;
        }
        else
        {
            r->down = p;
            r = p;
        }

        s = p;
        cout << "Enter the adjacent nodes of " << p->node << ":\n";

        do
        {
            cout << "Adjacent node: ";
            q = create();
            s->next = q;
            s = q;

            cout << "Continue adjacent nodes of " << p->node << "? (Y/N): ";
            ch = getche();

        } while (toupper(ch) == 'Y');

        cout << "\nContinue entering parent nodes? (Y/N): ";
        ch = getche();

    } while (toupper(ch) == 'Y');

    print();
    dfs();

    getch();
}
