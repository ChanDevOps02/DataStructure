
/*Stack DataStructure*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class stack
{
private:
	int* arr;
	int top;
	int capacity;
public:
	stack(int size)
	{
		arr = new int[size];
		capacity = size;
		top = -1;
	}
	void push(int val)
	{
		if (isFull() == 1)
		{
			cout << "Stack Overflow!";
			return;
		}
		else
		{
			top++;
			arr[top] = val;
			cout << val << " has been pushed in the stack!" << endl;
		}
	}
	int pop()
	{
		if (isEmpty() == 1)
		{
			cout << "Stack underflow!";
			return 0;
		}
		else
		{
			cout << "Data that pushed lately has been poped!" << endl;
			return arr[top--];
		}
	}
	bool isFull()
	{
		if (top == capacity - 1)
		{
			return 1;
		}
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return 1;
		}
	}
	int peek()
	{
		if (top == -1)
		{
			cout << "Stack underflow!";
			return 0;
		}
		else
		{
			return arr[top];
		}
	}
	int size()
	{
		return top + 1;
	}
	~stack()
	{
		delete[] arr;
	}
};
int main(void)
{
	stack s(5);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	cout << "Top element : " << s.peek() << endl;
	cout << "Stack size : " << s.size() << endl;
	s.pop();
	cout << "Top element after pop : " << s.peek() << endl;
	s.push(60);
	cout << "Top element after push : " << s.peek() << endl;
	return 0;
}
