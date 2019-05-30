#import <stdio.h>

struct Node {
    int data;
    Node* next;
};

bool isJoinedSimple(Node* n1, Node* n2) {
    while(n1->next != NULL) {
        n1 = n1->next;
    }
    while(n2->next != NULL) {
        n2 = n2->next;
    }
    return n1 == n2;
}
