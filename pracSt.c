#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int arr[SIZE];
int top;

void push(int data)
{
    if (top == SIZE - 1)
    {
        printf("\nStack Is Full");
        return;
    }
    else
    {
        top++;
        arr[top] = data;
        printf("\n%d inserted successfully.", data);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is Empty");
        return;
    }
    else
    {
        printf("\n%d removed successfully.", arr[top]);
        top--;
    }
}

void main()
{
    top = -1;
    push(10);
    pop();
    pop();
}
