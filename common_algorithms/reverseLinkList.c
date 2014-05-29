#include <stdio.h>

struct Node
{
    int value;
    Node *next;
};

typedef Node *PNode;

void reverseLinkList(PNode head)
{
    if (head == NULL || head->next == NULL) return;
    PNode *pre, *cur, *next;
    pre = head;
    cur = head->next;
    next = NULL;
    while (cur != NULL)
    {
    	next = cur->next;
	cur->next = pre;
	pre = cur;
	cur = next;
    }
}

void printLinkList(PNode head)
{
    PNode *p = head;
    while (p != NULL)
        printf("%d ", p->value);
    printf("\n");
}

PNode arrayToLinkList(int *array, int size)
{
    PNode head, cur;
    for (int i=0; i<size; ++i)
    {
        Node *node = new Node();
	node->value = array[i];
	node->next = NULL;

	if (head == NULL)
	{
	    head = node;
	    cur = head;
	    continue;
	}
	cur->next = node;
	cur = node;
    }
    return head;
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    PNode head = arrayToLinkList(array, sizeof(array)/sizeof(int));
    printLinkList(head);
    
    reverseLinkList(head);
    printf("after reverse : \n");
    printLinkList(head);

    return 0;
}
