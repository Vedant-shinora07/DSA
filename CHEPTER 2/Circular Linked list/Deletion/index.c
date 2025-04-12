//  delete element at the index in the circular linked list

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void Traversal(struct Node* head) {
    struct Node* ptr = head;

    do {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
}
struct Node* DeleteIndex(struct Node* head, int index) {
    if(head == NULL) return NULL;

    if(head == head->next) {
        free(head);
        return NULL;
    }
    if(index == 0) {
        struct Node* a = head;
        struct Node* b = head;

        while(a->next != head) {
            a = a->next;
        }
        a->next = head->next;
        head = head->next;
        free(b);
        return head;
    }

    struct Node* p = head;
    struct Node* q = head ->next;
    int i=0;
    while(i != index-1 && p->next != head) {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    return head;

}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));   
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head -> data = 7;
    head -> next = second;

    second -> data = 13;
    second -> next = third;

    third -> data = 17;
    third -> next = fourth;

    fourth -> data = 23;
    fourth -> next = head;

    head = DeleteIndex(head,2);
    Traversal(head);
    
}