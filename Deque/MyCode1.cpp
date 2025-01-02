#include <iostream>
using namespace std;
class Deque
{
private:
	int* arr;
	int size;
	int Max_Size;
	int rear;
	int front;
public:
	Deque(int capacity) : size(0), rear(0), front(0)
	{
		arr = new int[capacity];
		Max_Size = capacity;
	}
	bool isFull()
	{
		if (size == Max_Size)
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
	}
	void Front_Push(int val)
	{
		if (isFull())
		{
			cout << "Deque is Full!" << endl;
			return;
		}
		front = (front - 1 + Max_Size) % Max_Size;
		arr[front] = val;
		size++;
	}
	void Rear_Push(int val)
	{
		if (isFull())
		{
			cout << "Deque is Full!" << endl;
			return;
		}
		arr[rear] = val;
		rear = (rear + 1) % Max_Size;
	}
	void Front_Pop()
	{
		if (isEmpty())
		{
			cout << "Deque is already Empty!" << endl;
			return;
		}
		front = (front + 1) % Max_Size;
		size--;
	}
	void Rear_Pop()
	{
		if (isEmpty())
		{
			cout << "Deque is already Empty" << endl;
			return;
		}
		rear = (rear - 1 + Max_Size) % Max_Size;
		size--;
	}
	int GetFront()
	{
		return arr[front];
	}
	int GetRear()
	{
		return arr[(rear - 1 + Max_Size) % Max_Size];
	}
};
int main(void)
{
	Deque myDeque(5);
	myDeque.Rear_Push(10);
	myDeque.Rear_Push(20); //10 20
	myDeque.Front_Push(30);
	myDeque.Front_Push(40); //40 30

	cout << "Front Value : " << myDeque.GetFront() << endl; //40
	cout << "Rear Value : " << myDeque.GetRear() << endl; //20

	myDeque.Front_Pop();
	myDeque.Rear_Pop(); //10 30

	cout << "Front Value : " << myDeque.GetFront() << endl;
	cout << "Rear Value : " << myDeque.GetRear() << endl;
	return 0;
}
