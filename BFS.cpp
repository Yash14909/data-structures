/* 
Program 14
Write a program to traverse the graph using BFS method
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
int que[10], visit[10], front, rear;

// Function to add node in queue
void addnode(int x)
{
    rear++;
    que[rear] = x;
    if (visit[x] == 0)
        visit[x] = 1;
}

// Function to delete node from queue
int del()
{
    int y;
    if (((rear == 9) && (front == rear)) || (front == rear + 1))
    {
        y = que[front];
        front = 0;
        rear = -1;
    }
    else
    {
        y = que[front];
        front++;
    }
    return (y);
}

// Function to print graph
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

// BFS traversal
void bfs()
{
    int inode, parent, flag;
    r = q = p = s = start;

    cout << "\n\nEnter the initial node: ";
    cin >> inode;

    cout << "\nBFS Traversal: " << inode << " ";
    addnode(inode);

    while ((rear != -1) || (front != rear + 1))
    {
        parent = del();
        p = start;
        flag = 0;

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
                        addnode(q->node);
                        flag = 1;
                    }
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

// Create a graph node
struct graph *create()
{
    struct graph *f;
    f = (struct graph *)malloc(sizeof(struct graph));
    f->next = NULL;
    f->down = NULL;
    cin >> f->node;
    return (f);
}

// Main function
void main()
{
    int no;
    char ch;
    clrscr();

    front = 0;
    rear = -1;
    start = NULL;

    cout << "Enter the graph structure for BFS traversal:\n";

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
    bfs();

    getch();
}
