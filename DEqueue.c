#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int deQueue[SIZE];
int front = -1, rear = -1;

int isFull()
{
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

int isEmpty()
{
    return (front == -1);
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("Queue is Full.\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deQueue[rear] = x;
    printf("%d inserted at rear.\n", x);
}

void fenqueue(int x)
{
    if (isFull())
    {
        printf("Queue is Full.\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
    {
        front--;
    }

    deQueue[front] = x;
    printf("%d inserted at front.\n", x);
}

void rdequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("%d removed from rear.\n", deQueue[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear--;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("%d removed from front.\n", deQueue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1)
    {
        printf("%d ", deQueue[i]);

        if (i == rear)
            break;

        if (i == SIZE - 1)
            i = 0;
        else
            i++;
    }
    printf("\n");
}

int main()
{
    int ch, n;

    while (1)
    {
        printf("\n=== DOUBLE ENDED QUEUE (NO MODULUS) ===\n");
        printf("1. Insert from Rear\n");
        printf("2. Insert from Front\n");
        printf("3. Delete from Rear\n");
        printf("4. Delete from Front\n");
        printf("5. Display\n");
        printf("6. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &n);
            enqueue(n);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &n);
            fenqueue(n);
            break;

        case 3:
            rdequeue();
            break;

        case 4:
            dequeue();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
