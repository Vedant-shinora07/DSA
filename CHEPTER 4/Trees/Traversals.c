// Inorder, Preorder, and Postorder Traversals

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->left = newNode->right = NULL;
    return newNode;
}

void inOrder(struct Node* root) {
    if(root) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root) {
    if(root) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if(root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);        
    }
}

struct Node* insertAtLeft(struct Node* root, int data) {
    if(!root) return createNode(data);

    root->left = createNode(data);
    return root->left;
}
struct Node* insertAtRight(struct Node* root, int data) {
    if(!root) return createNode(data);

    root->right = createNode(data);
    return root->right;
}

int main() {
    struct Node* root = createNode(50);

    insertAtLeft(root, 30);
    insertAtRight(root, 70);
    
    insertAtLeft(root->left, 20);
    insertAtRight(root->left, 40);
    
    insertAtLeft(root->right, 60);
    insertAtRight(root->right, 80);
    
    printf("inorder : ");
    inOrder(root);
    
    printf("preOrder : ");
    preOrder(root);
    
    printf("postorder : ");
    postOrder(root);

}
