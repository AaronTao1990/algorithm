// thinking
// 1. use recursive function call to get a circle call, but the problem is when to exit the program bcz if is not allowed
// 2. to run a procedure n times, we can new an array of size n, then the procedure will be called n times
// 3. divide the procedure into two functions, one for existance, one for circle, and use the !!n trick to switch between the two functions

#include <stdio.h>

class Foo
{
public:
	Foo()
	{
		current_++;
		sum_ += current_;
	}
	~Foo() {}

	static void reset()
	{
		current_ = 0;
		sum_ = 0;
	}

	static int getSum()
	{
		return sum_;
	}

private:
	static int current_;
	static int sum_;
};

int Foo::current_ = 0;
int Foo::sum_ = 0;

int fabSum(int n)
{
	Foo::reset();
	Foo *pFoo = new Foo[n];
	int sum = Foo::getSum();
	delete []pFoo;
	return sum;
}

/*--------------------------------------------*/

typedef int (*pfunc)(int n);
pfunc array[2];

int first(int n)
{
	return 0;
}

int second(int n)
{
	return array[!!n](n-1) + n;
}

int fabSum1(int n)
{
	array[0] = first;
	array[1] = second;
	return second(n);
}

int main()
{
	int sum = fabSum1(10);
	printf("%d\n", sum);
	return 0;
}
