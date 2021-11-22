#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
} *temp,*head,*newnode,*temp_prev,*y;

void create();
void insertion_at_begining();
void insertion_at_middle();
void insertion_at_end();
void deletion_at_begining();
int deletion_at_middle();
void deletion_at_end();
void count_even();
void count_odd();
void odd_to_even();
void count_seven();
struct node*rev_list(struct node*first);
int main()
{
int favour;
printf("\n-----------------------------------------");
printf("\nHere are some operations for linked lists");
printf("\n1.create list");
printf("\n2.insertion at begining");
printf("\n3.insertion at middle");
printf("\n4.insertion at end");
printf("\n5.deletion at begining");
printf("\n6.deletion at middle");
printf("\n7.deletion at end");
printf("\n8.count even numbers");
printf("\n9.count odd numbers");
printf("\n10.odd to even  numbers");
printf("\n11.count numbers divisible by 7");
printf("\n12.Reverse");
do
{
printf("\n enter the operation to be performed");
scanf("%d",&favour);
switch(favour)
{
case 1: 
create();
break;
case 2:
insertion_at_begining();
break;
case 3: 
insertion_at_middle();
break;
case 4: 
insertion_at_end();
break;      
case 5: 
deletion_at_begining();
break;        
case 6: 
deletion_at_middle();
break;       
case 7: 
deletion_at_end();
break;  
case 8:
count_even();
break;
case 9:
count_odd();
break;
case 10:
odd_to_even();
break;
case 11:
count_seven();
break;
case 12:
    y=rev_list(head);
    while(y!=NULL){
        printf("Data :%d",y->data);  
        y=y->next;
        
    }
    break;
default:
printf("enter the valid value");
exit(0);
}
}while(1);
return 0;
}
void create()
{
int data;
head=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
{
printf("Error in memory allocation");
}
else
{
printf("enter the data to the linked list:");
scanf("%d",&data);
head->data=data;
head->next=NULL;
}
printf("the new edited linked list is:");
temp=head;
while(temp!=NULL)
{
printf("\nData:%d",temp->data);
temp=temp->next;
}
}


void insertion_at_begining()
{
int data;
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\nError in memory allocation");
exit(0);
}
else
{
printf("\nEnter the data inserted at begining of linked list:");
scanf("%d",&data);
newnode->data=data;
newnode->next=head;
head=newnode;
}
printf("the new edited linked list is:");
temp=head;
while(temp!=NULL)
{
printf("\nData:%d",temp->data);
temp=temp->next;
}
}

void insertion_at_middle()
{
int val;
    struct node* ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Memory Not Allocated !");
        exit(1);
    }
    printf("After which value you want to insert = ");
    scanf("%d",&val);
    printf("Enter the Number to be Added Middle :");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    temp=head;
    while (temp->data!=val){
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Number not found !");
            exit(1);
        }
    }    
    ptr->next=temp->next;
    temp->next=ptr;
    

printf("\nthe new edited linked list is\n:");
temp=head;
while(temp!=NULL)
{
printf("\n Data :%d",temp->data);
temp=temp->next;
}
}

void insertion_at_end()
{
int data;
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("error in memory allocation");
exit(0);
}
else
{
printf("\nenter the data to be entered in end:");
scanf("%d",&data);
newnode->data=data;
newnode->next=NULL;
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
printf("\nThe new edited linked list is:");
temp=head;
while(temp!=NULL)
{
printf("\nData:%d",temp->data);
temp=temp->next;
}
}

void deletion_at_begining()
{
printf("Enter the data to be deleted");
temp=head;
head=head->next;
free(temp);
printf("\n the new edited linked list is:");
temp=head;
while(temp!=NULL)
{
printf("\nData:%d",temp->data);
temp=temp->next;
}
}

int deletion_at_middle()
{
    
    int x;
	printf("\nEnter the data you want to delete: ");
    scanf("%d", &x);
    int i;
    struct node *current =head;
    struct node *previous =NULL;
    if(head == NULL)
    {
        printf("List is already empty.");
    }
while(current->data!=x)
{
    if(current->next==NULL)
    {
        return NULL;
    }
    else
    {
        previous=current;
        current=current->next;
    }
}
    if(current==head)
    {
        head=head->next;
    }
    else
    {
        previous->next=current->next;
    }
printf("\nthe list is:");
temp=head;
while(temp!=NULL)
{
printf("\nData:%d",temp->data);
temp=temp->next;
}
}

void deletion_at_end()
{
   
temp=head;
temp_prev=head;
temp=temp->next;
while(temp->next!=NULL)
{
temp_prev=temp;
temp=temp->next;
}
temp_prev->next=NULL;
free(temp);
printf("\nthe new edited linked list is:");
temp=head;
while(temp!=NULL)
{
printf("\nData:%d",temp->data);
temp=temp->next;
}
}
void count_even()
{
    int count=0;
    struct node*t=head;
    while(t!=NULL)
    {
       if(t->data%2==0)
       {
           count++;
       }
        t=t->next;   
    }
    printf("The even numbers in the list are =  %d\n",count);
}
void count_odd()
{
    int count=0;
    struct node*t=head;
    while(t!=NULL)
    {
       if(t->data%2!=0)
       {
           count++;
       }
        t=t->next;   
    }
    printf("The odd numbers in the list are =  %d\n",count);
}
void odd_to_even()
{
    struct node*t=head;
    while(t!=NULL)
    {
       if(t->data%2!=0)
       {
           t->data=(t->data*2);
       }
        t=t->next;   
    }
    printf("The odd to even numbers in the list are ");
 
    temp=head;
    while(temp!=NULL)
    {
       printf("\nData:%d",temp->data);
       temp=temp->next;
    }
}
void count_seven()
{
    int count=0;
    struct node*t=head;
    while(t!=NULL)
    {
       if(t->data%7==0)
       {
           count++;
       }
        t=t->next;   
    }
    if(count>1)
    {
    printf("Yes there are numbers divisible by 7\n");
    printf("The number of elements divisible by 7 are =  %d\n",count);
    }
}
struct node*rev_list(struct node*first)
{
    struct node*sec,*rest;
    if(first==NULL)
        return NULL;
    else if(first->next==NULL)
        return first;
    sec=first->next;
    rest=sec->next;
    first->next=NULL;
    while(1){
        sec->next=first;
        first=sec;
        sec=rest;
        rest=rest->next;
        if(rest==NULL)
           break;
    }
    sec->next=first;
}
/*
-----------------------------------------
Here are some operations for linked lists
1.create list
2.insertion at begining
3.insertion at middle
4.insertion at end
5.deletion at begining
6.deletion at middle
7.deletion at end
8.count even numbers
9.count odd numbers
10.odd to even  numbers
11.count numbers divisible by 7
12.Reverse
 enter the operation to be performed1
enter the data to the linked list:0
the new edited linked list is:
Data:0
 enter the operation to be performed2

Enter the data inserted at begining of linked list:1
the new edited linked list is:
Data:1
Data:0
 enter the operation to be performed4

enter the data to be entered in end:3.

The new edited linked list is:
Data:1
Data:0
Data:3
 enter the operation to be performed3
After which value you want to insert = 0
Enter the Number to be Added Middle :2

the new edited linked list is
:
 Data :1
 Data :0
 Data :2
 Data :3
 enter the operation to be performed6

Enter the data you want to delete: 0

the list is:
Data:1
Data:2
Data:3
 enter the operation to be performed*/

