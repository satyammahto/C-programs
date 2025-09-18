#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int stack[SIZE];
int top;

void push(int x)
{
    if (top == SIZE - 1)
        printf("\nWARNING :: STACK IS FULL");
    else
    {
        top++;
        stack[top] = x;
        printf("\n%d inserted successfully.", x);
    }
}

void pop()
{
    if (top == -1)
        printf("\nWARNING :: STACK IS EMPTY");
    else
    {
        int temp = stack[top];
        printf("\n%d removed successfully", temp);
        top--;
    }
}

void display()
{
    if (top == -1)
        printf("\nWARNING :: STACK IS EMPTY");
    else
    {
        printf("STACK : ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
    }
}

void peek()
{
    if (top == -1)
        printf("\nWARNING :: STACK IS EMPTY");
    else
        printf("\nTop most value is : %d.", stack[top]);
}

int main()
{
    top = -1;
    int ch, n;

    while (1)
    {

        printf("\n===STACK OPERATIONS===\n");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.PEEK");
        printf("\n4.DISPLAY");
        printf("\n5.QUIT");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter your Value : ");
            scanf("%d", &n);

            push(n);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("\nWARNING :: INVALID CHOICE!!!");
        }
    }
    return 0;
}