#include <algorithm>
#include <stdio.h>

struct Node
{
	int value;
	Node* left;
	Node* right;
};

void constructBST(Node*& cur, int value)
{
	Node* temp = new Node();
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;

	if (cur == NULL)
	{
		cur = temp;
		return;
	}
	
	Node* p = cur;
	while (p!=NULL)
	{
		if (value > p->value)
		{
			if (p->right != NULL)
			{
				p = p->right;
			}
			else
			{
				p->right = temp;
				break;
			}
		}
		else if (value < p->value)
		{
			if (p->left != NULL)
			{
				p = p->left;
			}
			else
			{
				p->left = temp;
				break;
			}
		}
	}
}

void inOrderTraverse(Node* root)
{
	if (root == NULL)
		return;

	inOrderTraverse(root->left);
	printf("%d\n", root->value);
	inOrderTraverse(root->right);
}

int maxDepth(Node* root)
{
	if (root == NULL)
		return 0;

	return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int longest = 0;
void getLongest(Node* root)
{
	if (root == NULL)
		return;

	getLongest(root->left);
	int distance = maxDepth(root->left) + maxDepth(root->right);
	if (distance > longest)
		longest = distance;
	getLongest(root->right);
}

int main()
{
	Node* root = NULL;
	constructBST(root, 3);
	constructBST(root, 2);
	constructBST(root, 1);
	constructBST(root, 4);
	constructBST(root, 0);

	printf("in order traverse the BST:\n");
	inOrderTraverse(root);
	printf("------------------\n");


	int maxDep = maxDepth(root);
	printf("maxDep : %d\n", maxDep);
	printf("------------------\n");

	getLongest(root);
	printf("longest : %d\n", longest);
	
	return 0;
}
