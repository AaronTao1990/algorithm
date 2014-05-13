#include <stdio.h>
#include <assert.h>

template <class T>
struct Node {
	T value;
	Node<T>* pre;
	Node<T>* next;
	Node<T>* curMax;
};

template <class T>
class Stack {
public:
	Stack();
	~Stack();
	
	typedef Node<T>* PNode;

	T top();
	void pop();
	T max();
	void push(T value);

private:
	PNode head;
	PNode cur;
	int size;
};

template <class T>
Stack<T>::Stack()
{
	size = 0;
}

template <class T>
Stack<T>::~Stack()
{
	PNode p;
	while (head!=NULL)
	{
		p = head->next;
		delete head;
		head = p;
	}
	size = 0;
}

template <class T>
T Stack<T>::top()
{
	assert(size>0);
	return cur->value;
}

template <class T>
void Stack<T>::pop()
{
	assert(size>0);
	if (size == 1)
	{
		delete head;
		head = NULL;
	}
	else
	{
		cur->pre->next = NULL;
		PNode p = cur;
		cur = cur->pre;
		delete p;
		
	}
	size--;
}

template <class T>
T Stack<T>::max()
{
	assert(size>0);
	return cur->curMax->value;
}


template <class T>
void Stack<T>::push(T value)
{
	PNode pnode = new Node<T>();
	pnode->value = value;
	pnode->pre = cur;
	pnode->next = NULL;
	if (size == 0)
	{
		pnode->curMax = pnode;
		head = pnode;
		cur = pnode;
	}
	else
	{
		if (value > cur->curMax->value)
			pnode->curMax = pnode;
		else
			pnode->curMax = cur->curMax;
		cur->next = pnode;
		cur = pnode;
	}
	size++;
}

int main()
{
	Stack<int> stack;
	stack.push(1);
	stack.push(3);
	stack.push(2);
	stack.push(4);
	
	printf("%d %d\n", stack.top(), stack.max());
	stack.pop();
	printf("%d %d\n", stack.top(), stack.max());
	stack.pop();
	printf("%d %d\n", stack.top(), stack.max());
	stack.pop();
	printf("%d %d\n", stack.top(), stack.max());
	stack.pop();
}
