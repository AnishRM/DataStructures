#include <stdio.h>  
#include <string.h>  
#define max 100  
int top,stack[max];  
void push(int x)
{  
if(top == max-1)
{  
        printf("stack overflow");  
      }  
else
  {  
        stack[++top]=x;  
      }  
}  
  
int pop()
{  
     return(stack[top--]);  
}  
int main()  
{  
   int arr[]={1,3,21,32,9,54};
    int len=6;
   int i;  
   printf("Numbers before reversing \n");
   for(i=0;i<len;i++)
    printf("%d\n",arr[i]);
  
   for(i=0;i<len;i++)  
        push(arr[i]);  

   for(i=0;i<len;i++)  
     arr[i]=pop(); 
   printf("Numbers after reversing \n");
    for(i=0;i<len;i++)
    printf("%d\n",arr[i]);
    return 0;
   
} 
/*Output
Numbers before reversing
1
3
21
32
9
54
Numbers after reversing
54
9
32
21
3
1



