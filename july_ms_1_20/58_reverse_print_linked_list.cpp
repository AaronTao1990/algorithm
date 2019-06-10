#include <stdio.h>

struct Node {
    int value;
    Node* next;
};

void addNode(Node* head, int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head->next;
    head->next = newNode;
}

void printList(Node* head) {
    Node* p = head->next;
    while(p) {
        printf("%d\n", p->value);
        p = p->next;
    }
}

void reversePrintList(Node* head) {
    if (head != NULL)
        if (head->next != NULL) {
            reversePrintList(head->next);
        }
        printf("%d\n", head->value);
}

int main() {
    Node* head = new Node();
    head->value = 0;
    head->next = NULL;

    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);
    printList(head);

    printf("-----------\n");

    reversePrintList(head->next);
}
