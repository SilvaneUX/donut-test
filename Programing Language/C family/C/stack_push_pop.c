//Write a program to implement a stack using an array with PUSH and POP operations

#include<stdio.h>

int stack[100],choice,n,top,x,i;

void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}


void pop()
{
    if(top<=-1)
    {
        printf("\nStack is under flow");
    }
    else
    {
        printf("\nThe popped elements is %d\n",stack[top]);
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        printf("\nThe elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\nPress Next Choice\n");
    }
    else
    {
        printf("\nThe STACK is empty\n");
    }
   
}


int main()
{
    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n STACK OPERATIONS USING ARRAY");
    printf("\n--------------------------------");
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}