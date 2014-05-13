#include <vector>

struct PathRec {
	std::vector<int> path;
	int sum;
	int target;
	bool bingo() {return sum==target;}
	bool add(int value) {
		if ((sum+value) > target)
			return false;
		path.push_back(value);
		sum += value;
		return true;
	}
	
	void remove()
	{
		sum -= path.back();
		path.pop_back();
	}

	void print() {
		std::vector<int>::const_iterator cit = path.begin();
		while (cit != path.end())
		{
			printf("%d ", *cit);
			++cit;
		}
		printf("\n");
	}
};

struct Node {
	int value;
	Node* left;
	Node* right;
};

void traverse(Node* root, PathRec* rec)
{
	if (root == NULL)
		return;
	
	if (!rec->add(root->value))
		return;

	if (root->left == NULL
		&& root->right == NULL)
	{
		if (rec->bingo())
		{
			rec->print();
			rec->remove();
			return;
		}
	}
	else if (rec->bingo())
	{
		rec->remove();
		return;
	}
	
	traverse(root->left, rec);
	traverse(root->right, rec);
	rec->remove();
}

int main()
{
	typedef Node* PNode;
	PNode root = NULL;

	PNode node1 = new Node();
	node1->value = 3;
	node1->left = NULL;
	node1->right = NULL;
	
	PNode node2 = new Node();
	node2->value = 3;
	node2->left = NULL;
	node2->right = NULL;

	PNode node3 = new Node();
	node3->value = 3;
	node3->left = NULL;
	node3->right = NULL;

	PNode node4 = new Node();
	node4->value = 3;
	node4->left = NULL;
	node4->right = NULL;
	
	root = node1;
	//node2->left = node4;
	node1->right = node2;
	node1->left = node3;

	PathRec rec;
	rec.target = 6;	
	rec.sum = 0;

	traverse(root, &rec);
	return 0;
}
