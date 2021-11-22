#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head=NULL;
struct node*temp;
void insert_beg(int x);
void insert_end(int x);
void insert_mid();
void delete_beg();
void delete_middle();
void delete_end();
void multiply();
void display();
void min();
void max();
int main()
{
    int favour,n,x;
printf("\n-----------------------------------------");
printf("\nHere are some operations for linked lists");
printf("\n1.insertion at begining");
printf("\n2.insertion at end");
printf("\n3.insertion at end");
printf("\n4.deletion at begining");
printf("\n5.deletion at middle");
printf("\n6.deletion at end");
while(1)
{
printf("\n enter the operation to be performed = ");
scanf("%d",&favour);
switch(favour)
{

case 1:
    printf("Enter the number:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data:");
        scanf("%d",&x);
        insert_beg(x);
    }
    display();
    break;
case 2: 
 printf("Enter the number:");
    scanf("%d",&n);
    int x;
    for(int i=0;i<n;i++)
    {
        printf("Enter the data:");
        scanf("%d",&x);
        insert_end(x);
    }
    display();
    break;
case 3: 
    insert_mid();
    display();
    break;      
case 4: 
    delete_beg();
    display();
    break;        
case 5: 
    delete_end();
    display();
    break;       
case 6: 
    delete_middle();
    display();
    break; 
case 7:
    multiply();
    break;
case 8:
    max();
    break;
case 9:
    min();
    break;
default:
printf("enter the valid value");
exit(0);
}
}
    printf("Enter the number:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data:");
        scanf("%d",&x);
        insert_beg(x);
    }
    display();
}
void insert_beg(int x)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insert_end(int x)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        struct node*t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=temp;
        temp->prev=t;
    }
}
void insert_mid()
{
    int val;
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*temp;
    if(ptr==NULL)
    {
        printf("NO memory allocated");
        exit(1);
    }
    printf("After which value you want to insert");
    scanf("%d",&val);
    printf("Enter the number to be added middle");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    temp=head;
    while(temp->data!=val)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Number not found");
            exit(1);
        }
    }
    ptr->next=temp->next;
    ptr->prev=temp;
    temp->next->prev=temp;
    temp->next=ptr;
}
void delete_beg()
{
    printf("deleting from begining\n");
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
     printf("list empty");
        return;
    }
    else if(head->next==NULL)
    {
        printf("only one elemnt in list and that is deleted");
        free(head);
        head=NULL;
    }
    else
    {
       temp=head;
       head=head->next;
       head->prev=NULL;
       free(temp);
       temp=NULL;
    }
    printf("\n");
}
void delete_end()
{
    printf("deleting from end\n");
    struct node*t=head;
    struct node*prev=head;
    if(head==NULL)
    {
        printf("list is empty:");
        return;
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        
    }
    else
    {
      while(t->next!=NULL)
      {
        prev=t;
        t=t->next;
      }
      prev->next=NULL;
      t->prev=NULL;
      free(t);
      t=NULL;
    }

    printf("\n");
}

void delete_middle()
{
    int y;
    if(head==NULL)
    {
        printf("the list is empty:");
        return;
    }
    else
    {
      struct node*t=head;
    printf("enter the data after which you want to delete:");
    scanf("%d",&y);  
    if(head->data==y)
    {
        delete_beg();
    }
    while(t->next->data!=y)
    {
        t=t->next;
    }
    temp=t->next;
    t->next=temp->next;
    temp->next->prev=t;
    free(temp);
    }
    
    printf("\n");
}
void multiply()
{
    struct node*t=head;
    printf("The list is\n");
    while(t!=NULL)
    {
        printf("%d\n",t->data*10);
        t=t->next;
    }
}
void min()
{
    struct node*m=head;
    int min=m->data;
    while(m!=NULL)
    {
        if(min>m->data)
        min=m->data;
        m=m->next;
    }
    printf("min is %d",min);
}
void max()
{
    struct node*m=head;
    int max=m->data;
    while(m!=NULL)
    {
        if(max<m->data)
        max=m->data;
        m=m->next;
    }
    printf("max is %d",max);
}
void display()
{
    struct node*ptr=head;
    printf("The list is\n");
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
/*
-----------------------------------------
Here are some operations for linked lists
1.insertion at begining
2.insertion at end
3.insertion at middle
4.deletion at begining
5.deletion at end
6.deletion at middle
 enter the operation to be performed = 1
Enter the number:3
Enter the data:13
Enter the data:15
Enter the data:17
The list is
17
15
13

 enter the operation to be performed = 2
Enter the number:2
Enter the data:12
Enter the data:11
The list is
17
15
13
12
11

 enter the operation to be performed = 3
After which value you want to insert15
Enter the number to be added middle14
The list is
17
15
14
13
12
11

 enter the operation to be performed = 5
deleting from end

The list is
17
15
14
13
12

 enter the operation to be performed = 6
enter the data which you want to delete:14

The list is
17
15
13
12*/





