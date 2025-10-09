/*Program 9
Write a program in CPP to implements Queue using Array. 
Run the code in Turbo C++*/

#include<iostream.h> 
#include<conio.h> 
#include<ctype.h> 
#include<stdlib.h> 
#define mx 20
int q[mx];
int r = -1, f=-1;

/* prototypes */ 
int qfull(void);
int qempty(void);
void addq(void); 
void delq(void); 
void displayq(void);

main()
{
char resp;
int ch;
do
{
clrscr();
cout<<" MENU\n";
cout<<"1. ADD\n"; 
cout<<"2, Delete\n";
cout<<"3. Display\n"; 
cout<<"4. Exit\n"; 
cout<<"Enter the choice\n"; 
cin>>ch;
switch(ch)
{
case 1 : addq(); break;

case 2 : delq(); break;

case 3 : displayq(); break; 
  
case 4: exit(1);
 
default :
cout<<"Invalid Choice... 1..4";
}
cout<<"Any more trials(y/n) "; 
resp=getche();
}
  while(toupper(resp)=='Y');
}

int qfull(void)
{
if(r==mx-1) 
return(1);
else return(0);
}

int qempty(void)
{
if(r==-1 && f==-1) 
return(1);
else
return(0);
}

void addq(void)
{
char resp; do
{
if(qfull()==1)
{
cout<<"Queue is full"; 
getch();
}
else
{
cout<<"\nEnter the element :"; cin>>q[++r];
/* sp case*/

if(f==-1) f=0;
}
cout<<"\n Do you want to add any more elements(y/n)"; resp=getche();
 
}while(toupper(resp)=='Y');
}

void delq(void)
{
char resp; do
{
if(qempty()==1)
{
cout<<"Queue is empty"; 
getch();
}
else
{
cout<<"deleted element is : "<<q[f++]; 
getch();
}
cout<<"Any more deletions(y/n)"; 
resp=getche();
}
  while(toupper(resp)=='Y');
}

void displayq(void)
{	
int i;
if(qempty()==1) 
cout<<"Queue is empty";
else
{
cout<<"Queue is \n"; 
for(i = f;i<=r;i++) 
cout<<"\t"<<q[i];
}
getch();
}
 
