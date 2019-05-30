#include <stdio.h>
#include <stack>

/*
 * binary search tree node
 */
template <class T>
struct Node {
	T value;
	Node<T>* left;
	Node<T>* right;
};

/*
 * add one node to the binary search tree
 */
template <class T>
void addBSTNode(Node<T>*& root, T value)
{
	if (root == NULL)
	{
		root = new Node<T>();
		root->value = value;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	
	if (root->value > value)
		addBSTNode(root->right, value);
	else if (root->value < value)
		addBSTNode(root->left, value);
	else
		return;
}

template <class T>
void inOrder(Node<T>* root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	printf("%d\n", root->value);
	inOrder(root->right);
}


/*
 * 1.traverse the BST non-recursively
 * 2.transform the BST to double-ended list
 * 3.return the pointer to the double-ended list head
 */
template <class T>
Node<T>* bst2blist(Node<T>* root)
{
	Node<T>* head = NULL, * pre = NULL;
	Node<T>* p = root;
	std::stack<Node<T>*> nodes;
	while (p!=NULL || !nodes.empty())
	{
		while (p!=NULL)
		{
			nodes.push(p);
			p = p->left;
		}
		
		if (!nodes.empty())
		{
			p = nodes.top();		// in the non-recursively traverse mode, every node of the BST is accessed by from the top of the stack

			if (pre == NULL)
				head = p;			// first(left-most) node supposed to be the head
			else
				pre->right = p;		// point previous node pointer to current node
			p->left = pre;			// point current node pointer to previous node
			pre = p;				// take current node as the new previous node

			printf("%d\n", p->value);
			nodes.pop();

			p = p->right;
		}
	}
	return head;
}

typedef Node<int>* PNode;
PNode head=NULL, pre=NULL;

template <class T>
void bst2blistInOrder(Node<T>* cur)
{
	if (cur==NULL)
		return;
	inOrder(cur->left);
	if (pre == NULL)
	{
		head = cur;
	}
	else
	{
		pre->right = cur;
		cur->left = pre;
	}
	pre = cur;
	inOrder(cur->right);
}


template <class T>
void printDlist(Node<T>* root)
{
	while (root != NULL)
	{
		printf("%d\n", root->value);
		root = root->right;
	}
}

int main()
{
	Node<int>* root = NULL;
	addBSTNode(root, 1);
	addBSTNode(root, 3);
	addBSTNode(root, 2);
	addBSTNode(root, 4);
	addBSTNode(root, 4);
	addBSTNode(root, 8);
	addBSTNode(root, 6);
	
	printf("-----after the construction of the BST-------\n");			
	inOrder(root);						// traverse the BST
	printf("-----in order traverse the BST and change it into a double-ended list-------\n");			
	/*
	PNode head = bst2blist(root);	// transform non-recursively
	printf("-----print the double-ended list-------\n");
	printDlist(head);					// print the transform result
	*/
	bst2blistInOrder(root);
	printDlist(head);					// print the transform result
	
	
	return 0;
}
