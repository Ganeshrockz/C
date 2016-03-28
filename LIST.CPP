#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node*link;
}node;
node *prev,*p,*head,*ll,*q;
//CREATING A NEW HEAD NODE
void create()
{
head=(node*)malloc(sizeof(node));
head->link=NULL;
}
//FUNCTION TO INSERT AT TAIL
void insert()
{
int x;
ll=(node*)malloc(sizeof(node));  //A NEW NODE
printf("\nEnter data : ");
scanf("%d",&x);
ll->data=x;   
ll->link=NULL;
p=head;
while(p->link!=NULL)       //LOOP TO POINT TO THE LAST ELEMENT IN THE LIST
{
p=p->link;
}
p->link=ll;
}
//FUNCTION TO DISPLAY THE LIST
void display()
{
p=head->link;
if(p==NULL)    //EMPTY CONDITION
printf("Empty");
while(p!=NULL)
{
printf("%d ",p->data);
p=p->link;
}
}
//DELETING AT TAIL
void delete1()
{
p=head->link;
prev=head;
//AT ANY INSTANCE OF TIME p WILL POINT TO A NODE AND prev WILL POINT TO THE PREVIOUS NODE
if(prev->link==NULL)
printf("\nLIST is empty");
while(p->link!=NULL)
{
p=p->link;
prev=prev->link;
}
printf("\nElement deleted is %d\n",p->data);
prev->link=NULL;
}
/*INSERT AT HEAD*/
void insert1()
{
int e;
printf("\nEnter element : ");
scanf("%d",&e);
p=head;
ll=(node*)malloc(sizeof(node)); //NEW NODE CREATION
ll->data=e;
ll->link=p->link;
p->link=ll;
}
//DELETE AT HEAD
void delete2()
{
int count=0;
prev=head;
p=prev->link;
prev->link=p->link;
}
void insertpos()
{
int count=1,po,e;
printf("\nEnter positon : ");
scanf("%d",&po);
printf("\nEnter element : ");
scanf("%d",&e);
ll=(node*)malloc(sizeof(node));
ll->data=e;
prev=head;
while(count<po)//LOOP TO GO TO THE POINT BEFORE THE POSITION SPECIFIED BY THE USER
{
prev=prev->link;
count++;
}
ll->link=prev->link;
prev->link=ll;
}
void deletepos()
{
int pos,count=1;
printf("\nEnter position : ");
scanf("%d",&pos);
prev=head;
p=prev->link;
while(count<pos)//LOOP TO GO TO THE POINT BEFORE THE POSITION SPECIFIED BY THE USER
{
p=p->link;
prev=prev->link;
count++;
}
prev->link=p->link;
p->link=NULL;
}
void main()
{
int c;
clrscr();
create();
do
{
printf("\n---MENU---");
printf("\n1.insert");
printf("\n2.Display");
printf("\n3.Delete");
printf("\n4.InsertHead");
printf("\n5.DeleteHead");
printf("\n6.InsertPosition");
printf("\n7.DeletePositon");
printf("\n8.Exit");
printf("\nEnter choice : ");
scanf("%d",&c);
switch(c)
{
case 1:
insert();
break;
case 2:
display();
break;
case 3:
delete1();
break;
case 4:
insert1();
break;
case 5:
delete2();
break;
case 6:
insertpos();
break;
case 7:
deletepos();
break;
case 8:
exit(0);
break;
default:
printf("\nInvalid Choice");
}
}while(c!=8);
getch();
}

