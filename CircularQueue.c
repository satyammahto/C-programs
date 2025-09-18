#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int cirQue[SIZE];
int front, rear;

void enqueue(int x)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Cannot insert because Queue is Full..");
        return;
    }

    else if (rear == SIZE - 1)
        rear = 0;

    else
    {
        if (front == -1)
            front = rear = 0;

        else
            rear++;
    }
    deQueue[rear] = x;
    printf("%d inserted successfully.", x);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Cannot remove because Queue is Empty...");
        return;
    }

    printf("%d removed successfully.", cirQue[front]);

    else if (front == rear)
        front = rear = -1;

    else
    {
        front++;
    }
}

void display()
{
    if (front == -1)
        printf("Cannot display because Queue is Empty...");

    else
    {
        printf("Queue : ");
        if (front < rear)
        {
            for (int i = front; i <= rear; i++)
                printf("%d ", cirQue[i]);
        }

        else
        {
            for (int i = front; i <= SIZE - 1; i++)
                printf("%d ", cirQue[i]);
            for (int i = 0; i <= rear; i++)
                printf("%d ", cirQue[i]);
        }
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
