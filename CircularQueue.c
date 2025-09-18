#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int cirQue[SIZE];
int front, rear;

void enqueue(int x)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Cannot insert because Queue is Full..\n");
        return;
    }

    if (front == -1) // First element
    {
        front = rear = 0;
    }
    else if (rear == SIZE - 1 && front != 0)
    {
        rear = 0; // Wrap around
    }
    else
    {
        rear++;
    }

    cirQue[rear] = x;
    printf("%d inserted successfully.\n", x);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Cannot remove because Queue is Empty...\n");
        return;
    }

    printf("%d removed successfully.\n", cirQue[front]);

    if (front == rear) // Only one element
    {
        front = rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0; // Wrap around
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Cannot display because Queue is Empty...\n");
        return;
    }

    printf("Queue : ");
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", cirQue[i]);
    }
    else
    {
        for (int i = front; i < SIZE; i++)
            printf("%d ", cirQue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", cirQue[i]);
    }
    printf("\n");
}

int main()
{
    front = rear = -1;
    int ch, n;

    while (1)
    {
        printf("\n===QUEUE OPERATIONS===\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. QUIT\n");

        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter your Value : ");
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
            printf("WARNING :: INVALID CHOICE!!!\n");
        }
    }
    return 0;
}
