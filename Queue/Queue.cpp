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
    Node* rear; // 맨 뒤 포인터
    Node* front; // 맨 앞 포인터

public:
    Queue()
    {
        rear = nullptr;
        front = nullptr;
    }

    // 큐에 데이터 추가 (Enqueue)
    void enqueue(int val)
    {
        Node* newNode = new Node(); // 새로운 리스트 노드 생성
        newNode->value = val; // 새로운 노드의 값 설정
        newNode->next = nullptr; // 새로운 노드의 next를 nullptr로 설정

        if (rear == nullptr) // 큐가 비어있는 경우
        {
            rear = newNode;
            front = newNode;
        }
        else
        {
            rear->next = newNode; // 기존 rear의 next에 새로운 노드 연결
            rear = newNode; // rear를 새로운 노드로 갱신
        }
    }

    // 큐에서 데이터 제거 (Dequeue)
    int dequeue()
    {
        if (front == nullptr) // 큐가 비어있을 경우
        {
            cout << "Queue is empty!" << endl;
            return -1; // 비어있으면 -1 반환
        }

        int temp_val = front->value; // front의 값 저장
        Node* temp = front; // front 노드를 임시로 저장
        front = front->next; // front를 다음 노드로 이동

        // front가 nullptr이면 큐가 비게 되므로 rear도 nullptr로 설정
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp; // 임시 노드를 삭제하여 메모리 해제
        return temp_val; // 제거한 값 반환
    }

    // 큐의 첫 번째 요소 반환 (peek)
    int peek()
    {
        if (front == nullptr) // 큐가 비어있으면
        {
            cout << "Queue underflow!" << endl;
            return -1; // 큐가 비었으면 -1 반환
        }
        return front->value; // front 값 반환
    }

    // 큐의 상태 출력
    void display()
    {
        if (front == nullptr) // 큐가 비어있으면
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) // 큐에 있는 모든 요소를 출력
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 큐가 비었는지 확인
    bool isEmpty()
    {
        return front == nullptr; // front가 nullptr이면 큐가 비어있는 상태
    }

    // 큐의 소멸자
    ~Queue()
    {
        while (!isEmpty()) // 큐가 비어있지 않으면 계속 dequeue
        {
            dequeue();
        }
    }
};

int main()
{
    Queue q;  // 큐 객체 생성

    // 큐에 데이터 추가 (Enqueue)
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // 큐의 상태 출력
    cout << "Queue after enqueuing 5 elements: ";
    q.display();

    // 큐에서 데이터 제거 (Dequeue)
    cout << "Dequeue: " << q.dequeue() << endl;

    // 큐의 첫 번째 요소 출력
    cout << "Front element: " << q.peek() << endl;

    // 큐의 상태 출력
    cout << "Queue after dequeue: ";
    q.display();

    return 0;
}
