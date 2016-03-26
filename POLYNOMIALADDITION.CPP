#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct list
{
int data,exp;
struct list*link;
}node;
node*head,*ll1,*head3,*prev,*q,*p,*ll,*head2;
void insert()
{
int d,e;
printf("\nEnter data and exp");
scanf("%d",&d);
scanf("%d",&e);
ll=(node*)malloc(sizeof(node));
ll->data=d;
ll->exp=e;
ll->link=NULL;
p=head;
while(p->link!=NULL)
{
p=p->link;
}
p->link=ll;
}
void display()
{
p=head->link;
while(p!=NULL)
{
printf("%d",p->data);
printf("x^%d ",p->exp);
p=p->link;
}
printf("\n");
}
void insert1()
{
int d,e;
printf("\nEnter data and exp");
scanf("%d",&d);
scanf("%d",&e);
ll1=(node*)malloc(sizeof(node));
ll1->data=d;
ll1->exp=e;
ll1->link=NULL;
p=head2;
while(p->link!=NULL)
{
p=p->link;
}
p->link=ll1;
}
void display1()
{
p=head2->link;
while(p!=NULL)
{
printf("%d",p->data);
printf("x^%d ",p->exp);
p=p->link;
}
printf("\n");
}
void sort()
{
int temp1,temp2;
p=head->link;
while(p!=NULL)
{
q=p->link;
while(q!=NULL)
{
if(p->exp<q->exp)
{
temp1=p->data;
temp2=p->exp;
p->data=q->data;
p->exp=q->exp;
q->data=temp1;
q->exp=temp2;
}
q=q->link;
}
p=p->link;
}
}
void sort1()
{
int temp1,temp2;
p=head2->link;
while(p!=NULL)
{
q=p->link;
while(q!=NULL)
{
if(p->exp<q->exp)
{
temp1=p->data;
temp2=p->exp;
p->data=q->data;
p->exp=q->exp;
q->data=temp1;
q->exp=temp2;
}
q=q->link;
}
p=p->link;
}
}
void add()
{
head3=(node*)malloc(sizeof(node));
head3->link=NULL;
p=head->link;
q=head2->link;
prev=head3;
while(p!=NULL||q!=NULL)
{
ll=(node*)malloc(sizeof(node));
if(p->exp>q->exp)
 {
ll->data=p->data;
ll->exp=p->exp;
p=p->link;
ll->link=NULL;
 }
else if(q->exp>p->exp)
 {
ll->data=q->data;
ll->exp=q->exp;
q=q->link;
ll->link=NULL;
 }
else if(p->exp==q->exp)
 {
ll->data=p->data+q->data;
ll->exp=p->exp;
if(p!=NULL)
{
p=p->link;
}
if(q!=NULL)
{
q=q->link;
}
ll->link=NULL;
 }
prev=head3;
while(prev->link!=NULL)
 {
prev=prev->link;
 }
prev->link=ll;
}
}
void dis()
{
p=head3->link;
while(p!=NULL)
{
printf("%d",p->data);
printf("x^%d ",p->exp);
p=p->link;
}
}
void main()
{
head=(node*)malloc(sizeof(node));
head->link=NULL;
head2=(node*)malloc(sizeof(node));
head2->link=NULL;
int n1,n2,a;
clrscr();
printf("Enter number of terms : ");
scanf("%d",&n1);
while(n1--)
{
insert();
}
display();
printf("\nEnter number of terms : ");
scanf("%d",&n2);
while(n2--)
{
insert1();
}
display1();
printf("\n***************\n");
sort();
sort1();
display();
display1();
getch();
add();
printf("******************\n");
dis();
getch();
}

