#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Structure that corresponds to a single node
typedef struct node
{
int data;
struct node *left,*right;
}node;
/*Structure for head node*/
typedef struct head
{
node* root;
}head;
void insert(head*t,int ele)
{
node *p,*q;
p=(node*)malloc(sizeof(node));
p->data=ele;
p->left=NULL;
p->right=NULL;
if(t->root==NULL)
{
t->root=p;
return;
}
q=t->root;
/*This loop searches for the element on the right or left half of the tree based 
on its magnitude with respect to the root node.
You can also use recursion to do this*/
while(q!=NULL)
{
if(ele<q->data)
{
if(q->left==NULL)
{
q->left=p;
break;
}
else
q=q->left;
}
else if(ele>q->data)
{
if(q->right==NULL)
{
q->right=p;
break;
}
else
q=q->right;
}
}
}
int search(head*t,int ele)
{
node *q=t->root;
while(q!=NULL)
{
if(q->data==ele)
return 1;
else if(ele>q->data)
q=q->right;
else if(ele<q->data)
q=q->left;
}
return 0;
}
/*This prints the left subtree,parent,right subtree*/
void inorder(node*t)
{
if(t!=NULL)
{
inorder(t->left);
printf("%d ",t->data);
inorder(t->right);
}
}
/*This prints the parent,left subtree,right subtree*/

void preorder(node*t)
{
if(t!=NULL)
{
printf("%d ",t->data);
preorder(t->left);
preorder(t->right);
}
}
/*This prints the left subtree,right subtree,parent*/
void postorder(node*t)
{
if(t!=NULL)
{
postorder(t->left);
postorder(t->right);
printf("%d ",t->data);
}
}
/*The technique used here is that max values are always found on the right of any node*/
node* max(node*x)
{
if(x->right==NULL)
return x;
else
return(max(x->right));
}
/*The technique used here is that min values are always found on the left of any node*/
node* min(node*x)
{
if(x->left==NULL)
return x;
else
return(min(x->left));
}
/*Function to find the parent of a particular child*/

node*parent(head*t,node*p)
{
node *q;
/*ROOT NODE*/
if(p==t->root)
return NULL;
q=t->root;
while(q!=NULL)
{
if(q->left==p||q->right==p)
return q;
if(p->data<=q->data)
q=q->left;
else
q=q->right;
}
return NULL;
}
/*DELETION HAS FOUR CASES*/

void delete1(head*t,int ele)
{
node*q;
if(t->root==NULL)
{
printf("\nBST is empty");
return;
}
q=t->root;
/*LOOP to search the element*/

while(q!=NULL)
{
if(ele==q->data)
break;
else if(ele>q->data)
q=q->right;
else
q=q->left;
}
if(q==NULL)
{
printf("\nElement not found");
return;
}
/*CASE 1
To delete the leaf nodes ie.NODES that dont have a child*/

if(q->left==NULL&&q->right==NULL)
{
if(q==t->root)
{
t->root=NULL;
return;
}
if(parent(t,q)->left==q)
parent(t,q)->left=NULL;
else
parent(t,q)->right=NULL;
return;
}
/*CASE 2
To delete any intermediate node having a left child*/

if(q->left!=NULL)
{
int val;
node*ptr=max(q->left);
val=ptr->data;
delete1(t,ptr->data);
q->data=val;
return;
}
/*CASE 3
To delete the root node*/

if(q==t->root)
{
t->root=t->root->right;
return;
}
/*CASE 4
To delete a node having a right child*/

if(parent(t,q)->left==q)
parent(t,q)->left=q->right;
else
parent(t,q)->right=q->right;
}
void main()
{
int c,ele;
head x;
clrscr();
/*Initially root must be NULL indicating that the tree is empty*/
x.root=NULL;
do
{
printf("\n---MENU---");
printf("\n1.INSERT");
printf("\n2.SEARCH");
printf("\n3.INORDER");
printf("\n4.PREORDER");
printf("\n5.POSTORDER");
printf("\n6.DELETE");
printf("\n7.EXIT");
printf("\n\nEnter choice : ");
scanf("%d",&c);
switch(c)
{
case 1:
printf("\nEnter data : ");
scanf("%d",&ele);
insert(&x,ele);
break;
case 2:
if(x.root==NULL)
{
printf("\nBST is EMPTY");
break;
}
printf("\nEnter element to be searched : ");
scanf("%d",&ele);
if(search(&x,ele)==1)
printf("\nElement %d is found",ele);
else if(search(&x,ele)==0)
printf("\nElement not found");
break;
case 3:
inorder(x.root);
break;
case 4:
preorder(x.root);
break;
case 5:
postorder(x.root);
break;
case 6:
if(x.root==NULL)
{
printf("\nBST is empty");
break;
}
printf("\nEnter element to be deleted : ");
scanf("%d",&ele);
delete1(&x,ele);
break;

}
}while(c!=7);
getch();
}
