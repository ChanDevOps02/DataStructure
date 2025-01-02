#include <iostream>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Deque() : front(nullptr), rear(nullptr), size(0) {}
    ~Deque() {
        while (!isEmpty()) {
            Pop_Front();
        }
    }

    int isEmpty() {
        return size == 0;
    }

    void Push_Front(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void Push_Rear(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int Pop_Front() {
        if (isEmpty()) {
            return -1;
        }
        Node* temp = front;
        int val = temp->value;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        }
        else {
            rear = nullptr; // 비어 있으면 rear도 nullptr로 설정
        }
        delete temp;
        size--;
        return val;
    }

    int Pop_Rear() {
        if (isEmpty()) {
            return -1;
        }
        Node* temp = rear;
        int val = temp->value;
        rear = rear->prev;
        if (rear) {
            rear->next = nullptr;
        }
        else {
            front = nullptr; // 비어 있으면 front도 nullptr로 설정
        }
        delete temp;
        size--;
        return val;
    }

    int amount() {
        return size;
    }

    int GetFront() {
        return isEmpty() ? -1 : front->value;
    }

    int GetRear() {
        return isEmpty() ? -1 : rear->value;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int amt, ordrnum;
    Deque mydeque;
    cin >> amt;

    for (int i = 0; i < amt; i++) {
        cin >> ordrnum;
        if (ordrnum == 1) {
            int num;
            cin >> num;
            mydeque.Push_Front(num);
        }
        else if (ordrnum == 2) {
            int num;
            cin >> num;
            mydeque.Push_Rear(num);
        }
        else if (ordrnum == 3) {
            cout << mydeque.Pop_Front() << '\n';
        }
        else if (ordrnum == 4) {
            cout << mydeque.Pop_Rear() << '\n';
        }
        else if (ordrnum == 5) {
            cout << mydeque.amount() << '\n';
        }
        else if (ordrnum == 6) {
            cout << mydeque.isEmpty() << '\n';
        }
        else if (ordrnum == 7) {
            cout << mydeque.GetFront() << '\n';
        }
        else if (ordrnum == 8) {
            cout << mydeque.GetRear() << '\n';
        }
    }

    return 0;
}
