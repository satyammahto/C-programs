#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Create a Node with value
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeg(struct Node **head, int value)
{
    struct Node *temp = createNode(value);
    temp->next = *head;
    *head = temp;
}

// Insert at last position
void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display linked list
void display(struct Node *head)
{
    struct Node *temp = head;
    printf("LinkedList: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search in linked list
void search(struct Node *head, int value)
{
    if (head == NULL)
    {
        printf("Cannot search, list is empty.\n");
        return;
    }

    struct Node *q = head;
    int position = 1;
    while (q != NULL)
    {
        if (q->data == value)
        {
            printf("Element %d found at position %d\n", value, position);
            return;
        }
        q = q->next;
        position++;
    }
    printf("Element %d not found in the list\n", value);
}

// Reverse a linked list
void reverse(struct Node **head)
{
    struct Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Delete node by value
void deleteByValue(struct Node **head, int value)
{
    if (*head == NULL)
    {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct Node *temp = *head, *prev = NULL;

    // If head node is to be deleted
    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", value);
        return;
    }

    // Search for node to delete
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
}

// Delete node at given position (1-based index)
void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct Node *temp = *head;

    if (position == 1)
    {
        *head = temp->next;
        free(temp);
        printf("Deleted node at position %d.\n", position);
        return;
    }

    struct Node *prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position %d not found in the list.\n", position);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted node at position %d.\n", position);
}

int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeg(&head, 5);
    display(head);

    search(head, 20);
    search(head, 50);

    deleteByValue(&head, 20);
    display(head);

    deleteAtPosition(&head, 2);
    display(head);

    reverse(&head);
    printf("Reversed ");
    display(head);

    return 0;
}
