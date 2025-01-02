#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

class Queue
{
private:
    Node* rear; // �� �� ������
    Node* front; // �� �� ������

public:
    Queue()
    {
        rear = nullptr;
        front = nullptr;
    }

    // ť�� ������ �߰� (Enqueue)
    void enqueue(int val)
    {
        Node* newNode = new Node(); // ���ο� ����Ʈ ��� ����
        newNode->value = val; // ���ο� ����� �� ����
        newNode->next = nullptr; // ���ο� ����� next�� nullptr�� ����

        if (rear == nullptr) // ť�� ����ִ� ���
        {
            rear = newNode;
            front = newNode;
        }
        else
        {
            rear->next = newNode; // ���� rear�� next�� ���ο� ��� ����
            rear = newNode; // rear�� ���ο� ���� ����
        }
    }

    // ť���� ������ ���� (Dequeue)
    int dequeue()
    {
        if (front == nullptr) // ť�� ������� ���
        {
            cout << "Queue is empty!" << endl;
            return -1; // ��������� -1 ��ȯ
        }

        int temp_val = front->value; // front�� �� ����
        Node* temp = front; // front ��带 �ӽ÷� ����
        front = front->next; // front�� ���� ���� �̵�

        // front�� nullptr�̸� ť�� ��� �ǹǷ� rear�� nullptr�� ����
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp; // �ӽ� ��带 �����Ͽ� �޸� ����
        return temp_val; // ������ �� ��ȯ
    }

    // ť�� ù ��° ��� ��ȯ (peek)
    int peek()
    {
        if (front == nullptr) // ť�� ���������
        {
            cout << "Queue underflow!" << endl;
            return -1; // ť�� ������� -1 ��ȯ
        }
        return front->value; // front �� ��ȯ
    }

    // ť�� ���� ���
    void display()
    {
        if (front == nullptr) // ť�� ���������
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) // ť�� �ִ� ��� ��Ҹ� ���
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // ť�� ������� Ȯ��
    bool isEmpty()
    {
        return front == nullptr; // front�� nullptr�̸� ť�� ����ִ� ����
    }

    // ť�� �Ҹ���
    ~Queue()
    {
        while (!isEmpty()) // ť�� ������� ������ ��� dequeue
        {
            dequeue();
        }
    }
};

int main()
{
    Queue q;  // ť ��ü ����

    // ť�� ������ �߰� (Enqueue)
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // ť�� ���� ���
    cout << "Queue after enqueuing 5 elements: ";
    q.display();

    // ť���� ������ ���� (Dequeue)
    cout << "Dequeue: " << q.dequeue() << endl;

    // ť�� ù ��° ��� ���
    cout << "Front element: " << q.peek() << endl;

    // ť�� ���� ���
    cout << "Queue after dequeue: ";
    q.display();

    return 0;
}
