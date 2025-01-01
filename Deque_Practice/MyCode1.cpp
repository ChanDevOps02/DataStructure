#include <iostream>
#define MAX_SIZE 100
using namespace std;
class Deque
{
private:
	int arr[MAX_SIZE];
	int size;
	int front;
	int rear;
public:
	Deque() : size(0), front(0), rear(0)
	{

	}
	bool isFull()
	{
		if (size == MAX_SIZE)
		{
			return true;
		}
		else
		{
			return false;
		}
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

	}//test2
	}
	void push_front(int val)
	{
		if (isFull())
		{
			cout << "Deque is Full!" << endl;
			return;
		}
		else
		{
			arr[front] = val;
			front = (front + 1) % MAX_SIZE;
			size++;
		}
	}
	void push_rear(int val)
	{
		if (isFull())
		{
			cout << "Deque is FUll!" << endl;
			return;
		}
		else
		{
			rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
			arr[rear] = val;
			size++;
		}
	}
	void pop_front()
	{
		if (isEmpty())
		{
			cout << "Deque is empty!" << endl;
			return;
		}
		else
		{
			front = (front - 1 + MAX_SIZE) % MAX_SIZE;
			size--;
		}
	}
	void pop_rear()
	{
		if (isEmpty())
		{
			cout << "Deque is Empty!" << endl;
			return;
		}
		else
		{
			rear = (rear + 1) % MAX_SIZE;
			size--;
		}
	}
	int GetFront()
	{
		return arr[(front - 1 + MAX_SIZE) % MAX_SIZE];
	}
	int GetRear()
	{
		return arr[rear];
	}
};
int main(void)
{
	Deque mydeque;
	mydeque.push_front(10);
	mydeque.push_front(20);
	mydeque.push_rear(90); 
	mydeque.push_rear(100); //10 20     100 90

	cout << "Front Value : " << mydeque.GetFront() << endl;//20
	cout << "Rear Value : " << mydeque.GetRear() << endl;//100

	mydeque.pop_front(); //20 delete
	mydeque.pop_rear(); //100 delete

	cout << "Front Value : " << mydeque.GetFront() << endl; //10
	cout << "Rear Value : " << mydeque.GetRear() << endl; //90
	return 0;
}