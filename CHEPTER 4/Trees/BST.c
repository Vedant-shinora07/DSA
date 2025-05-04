// Binary search tree operations..

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct Node *insertNode(struct Node *root, int data)
{
    if (!root)
        return createNode(data);
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct Node *successor(struct Node *root)
{
    struct Node *ptr = root;
    while (ptr && ptr->left)
    {
        ptr = ptr->left;
    }
    return ptr;
}

struct Node* deleteNode(struct Node *root, int value)
{
    if (!root)
        return root;

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if(!root->left) {
            struct Node* ptr = root->right;
            free(root);
            return ptr;
        }
        else if(!root->right) {
            struct Node* ptr = root->left;
            free(root);
            return ptr;
        }
        struct Node* ptr = successor(root->right);
        root->data = ptr->data;
        root->right = deleteNode(root->right, ptr->data);
    }
    return root;
}
int main() {
    struct Node* root = NULL;

    root = insertNode(root,10);
    root = insertNode(root,20);
    root = insertNode(root,30);
    root = insertNode(root,40);
    root = insertNode(root,50);
    root = insertNode(root,60);
    root = insertNode(root,70);
    root = insertNode(root,80);

    printf("Inorder Traversal : ");
    inorder(root);
    printf("\n");

    root =deleteNode(root, 20);
    printf("Inorder after deleting : ");
    inorder(root);
}