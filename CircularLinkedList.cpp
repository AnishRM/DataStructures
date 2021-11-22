#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
int data;
struct node *next;
}*head,*tail,*temp,*t,*prev;
void createnode();
void createlink(int n);
void traverse();
void insertbeg();
void insertmid();
void insertend();
void deletebeg();
void deletemid();
void deleteend();
int main()
{
int a,b;

while(1)
{
printf("enter 1 for createlink ,2 for insert at beg, 3 for insert at mid,4 for insert at end, 5 for delete beg,6 for delete mid, 7 for delete end ,8 for traverse 9 for exit ");
scanf("%d",&a);
switch(a)
{
case 1: {
printf("enter no of nodes in list");
scanf("%d",&b);
createlink(b);
break;
}
case 2:{
insertbeg();
break;
}
case 3: {
insertmid();
break;
}
case 4:insertend();
break;
case 5:deletebeg();
break;
case 6:deletemid();
break;
case 7:deleteend();
break;
case 8:traverse();
break;
            case 9:exit(0);
}
}
return(0);
}
void createnode()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("enter data :\n");
scanf("%d",&temp->data);
temp->next=NULL;
}
void createlink(int n)
{
int i;
for(i=0;i<n;i++)
{
createnode();
if(head==NULL)
{
head=temp;
tail=head;
}
else
{
temp->next=head;
tail->next=temp;
tail=tail->next;

}
}
}
void traverse()
{
temp=head;
while(temp->next!=head)
{
printf("%d->",temp->data);
temp=temp->next;
}
printf("%d",temp->data);
printf("\n");
}
void insertbeg()
{
createnode();
if(head==NULL)
{
head=temp;
tail=head;
}
else
{
   tail->next=temp;
temp->next=head;
head=temp;
}
printf("linked list after insertion at beg\n");
traverse();
}
void insertmid()
{
int x;
printf("enter the data after which want to insert");
scanf("%d",&x);
t=head;
while(t->data!=x)
{
t=t->next;
}
if(t->data==x)
{
createnode();
temp->next=t->next;
t->next=temp;
printf("the linked list after insertion at mid");
traverse();
}
}
void insertend()
{
createnode();
if(head==NULL)
{
head=temp;
tail=head;
}
else
{
tail->next=temp;
temp->next=head;
tail=temp;
}
printf("the linked list after insertion at end");
traverse();
}
void deletebeg()
{

if(head==NULL)
{
printf("no linked list found ");
}
else if(head->next==NULL)
{
free(head);
}
else
{
   
temp=head;
head=head->next;
tail->next=head;
free(temp);



}
printf("the linked list after deletion at beg");
traverse();
}
void deleteend()
{
temp=head;
if(temp==NULL)
{
printf("there is no linked list");
}
else
{
while(temp->next!=head)
{
t=temp;
temp=temp->next;
}
t->next=head;
free(temp);
}
printf("the linked list after deletion at end");
traverse();
}
void deletemid()
{
int a;
printf("enter data to delete");
scanf("%d",&a);
temp=head;
while(temp->data!=a)
{
t=temp;
temp=temp->next;
}
t->next=temp->next;
free(temp);
printf("the linked list after deletion at mid");
traverse();
}
/*
enter 1 for createlink ,2 for insert at beg, 3 for insert at mid,4 for insert at end, 5 for delete beg,6 for delete mid, 7 for delete end ,8 for traverse 9 for exit 1
enter no of nodes in list3
enter data :
21
enter data :
23
enter data :
24
enter 1 for createlink ,2 for insert at beg, 3 for insert at mid,4 for insert at end, 5 for delete beg,6 for delete mid, 7 for delete end ,8 for traverse 9 for exit 2
enter data :
19
linked list after insertion at beg
19->21->23->24
enter 1 for createlink ,2 for insert at beg, 3 for insert at mid,4 for insert at end, 5 for delete beg,6 for delete mid, 7 for delete end ,8 for traverse 9 for exit 3
enter the data after which want to insert21
enter data :
22
the linked list after insertion at mid19->21->22->23->24
enter 1 for createlink ,2 for insert at beg, 3 for insert at mid,4 for insert at end, 5 for delete beg,6 for delete mid, 7 for delete end ,8 for traverse 9 for exit 4
enter data :

32
the linked list after insertion at end19->21->22->23->24->32
enter 1 for createlink ,2 for insert at beg, 3 for insert at mid,4 for insert at end, 5 for delete beg,6 for delete mid, 7 for delete end ,8 for traverse 9 for exit 6
enter data to delete24
the linked list after deletion at mid19->21->22->23->32
enter 1 for createlink ,2 for insert at beg, 3 for insert at mid,4 for insert at end, 5 for delete beg,6 for delete mid, 7 for delete end ,8 for traverse 9 for exit 8
19->21->22->23->32
enter 1 for createlink ,2 for insert at beg, 3 for insert at mid,4 for insert at end, 5 for delete beg,6 for delete mid, 7 for delete end ,8 for traverse 9 for exit 9

--------------------------------
Process exited after 85.76 seconds with return value 0
Press any key to continue . . .




