#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *insert(struct Node *root, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else if (x < root->data)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }

    return root;
}

void display(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

void search(int value)
{
    struct Node *q;
    if (root == NULL)
    {
        printf("Tree Doesn't exist.");
        return;
    }
    q = root;
    int depth = 1;
    while (q != NULL)
    {
        if (q->data == value)
        {
            printf("\nValue found at depth %d", depth);
            return;
        }
        else if (q->data > value)
        {
            q = q->left;
        }
        else
        {
            q = q->right;
        }
        depth++;
    }
    printf("\nValue not found.");
}
struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct Node *delete(struct Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > value)
    {
        root->left = delete(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = delete(root->right, value);
    }
    else
    {
        // case 1 : No child
        if (root->left == NULL && root->right == NULL)
        {
            root = NULL;
        }
        // case 2 : one child
        else if (root->left == NULL)
        {
            root = root->right;
        }
        else if (root->right == NULL)
        {
            root = root->left;
        }
        else
        {
            struct Node *temp = findMin(root->right);
            root->data = temp->data;
        }
    }
    return root;
}

int main()
{

    root = insert(root, 30);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 8);
    printf("Inorder : ");
    display(root);
    search(20);
    root = delete(root, 10);
    printf("\nInorder : ");
    display(root);

    return 0;
}