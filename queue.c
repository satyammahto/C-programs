#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int que[SIZE];
int front, rear;

void enqueue(int x)
{
    if (rear == SIZE - 1)
        printf("\nWARNING! :: QUEUE IS FULL");
    else if (rear == -1)
    {
        front = rear = 0;
        que[rear] = x;
        printf("\n%d inserted successfully.", x);
    }
    else
    {
        rear++;
        que[rear] = x;
        printf("\n%d inserted successfully.", x);
    }
}

void dequeue()
{
    if (front == -1)
        printf("\nWARNING! :: QUEUE IS EMPTY");
    else
    {
        printf("\n%d removed successfully", que[front]);
        front++;
    }
}

void display()
{
    if (front == -1)
        printf("\nWARNING! :: QUEUE IS EMPTY");
    else
    {
        printf("\nQueue : ");
        for (int i = front; i <= rear; i++)
            printf("%d ", que[i]);
    }
}

int main()
{
    front = rear = -1;
    int ch, n;

    while (1)
    {

        printf("\n===QUEUE OPERATIONS===\n");
        printf("\n1.INSERT");
        printf("\n2.DELETE");
        printf("\n3.DISPLAY");
        printf("\n4.QUIT");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter your Value : ");
            scanf("%d", &n);

            enqueue(n);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\nWARNING :: INVALID CHOICE!!!");
        }
    }
    return 0;
}