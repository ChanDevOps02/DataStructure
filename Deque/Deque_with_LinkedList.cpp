#include <iostream>
using namespace std;
struct Node
{
	Node* next;
	Node* prev;
	int value;
};
class Deque
{
private:
	Node* front;
	Node* rear;
	int size;
public:
	Deque() : front(nullptr), rear(nullptr), size(0)
	{

	}
	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Front_Push(int val)
	{
		Node* newNode = new Node;
		newNode->value = val;
		if (isEmpty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}
		size++;
	}
	void Rear_Push(int val)
	{
		Node* newNode = new Node;
		newNode->value = val;
		if (isEmpty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->next = newNode;
			newNode->prev = rear;
			rear = newNode;
		}
		size++;
	}
	void Front_Pop()
	{
		if (isEmpty())
		{
			cout << "Deque is already empty!" << endl;
			return;
		}
		else if (front == rear)
		{
			front = rear = nullptr;
		}
		else
		{
			front = front->next;
			front->prev = nullptr;
		}
		size--;
	}
	void Rear_Pop()
	{
		if (isEmpty())
		{
			cout << "Deque is already empty!" << endl;
			return;
		}
		else if (front == rear)
		{
			front = rear = nullptr;
		}
		else
		{
			rear = rear->prev;
			rear->next = nullptr;
		}
		size--;
	}
	int GetFront()
	{
		if (isEmpty())
		{
			cout << "Cannot find any value in this Deque! Its Empty" << endl;
			return -1;
		}
		return front->value;
	}
	int GetRear()
	{
		if (isEmpty())
		{
			cout << "Cannot find any value in this Deque! Its Empty" << endl;
			return -1;
		}
		return rear->value;
	}
};
int main(void)
{
	Deque mydeque;
	mydeque.Front_Push(10);
	mydeque.Front_Push(20); //20 10
	mydeque.Rear_Push(100);
	mydeque.Rear_Push(90); //100 90     20 10

	cout << "Front Value : " << mydeque.GetFront() << endl; //20
	cout << "Rear Value : " << mydeque.GetRear() << endl;//90

	mydeque.Front_Pop();
	mydeque.Rear_Pop(); //100   10

	cout << "Front Value : " << mydeque.GetFront() << endl; //10
	cout << "Rear Value : " << mydeque.GetRear() << endl; //100
	return 0;
}