#include <iostream>
#include <queue>
using namespace std;

class StackTwoQ {
    queue<int> q1, q2; 

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << x << " pushed into stack (TwoQ)." << endl;
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << q1.front() << " popped (TwoQ)." << endl;
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element (TwoQ): " << q1.front() << endl;
    }
};

class StackOneQ {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed into stack (OneQ)." << endl;
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << q.front() << " popped (OneQ)." << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element (OneQ): " << q.front() << endl;
    }
};

int main() {
    cout << "--- Stack using Two Queues ---" << endl;
    StackTwoQ s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.top();
    s1.pop();
    s1.top();

    cout << "\n--- Stack using One Queue ---" << endl;
    StackOneQ s2;
    s2.push(5);
    s2.push(15);
    s2.push(25);
    s2.top();
    s2.pop();
    s2.top();

    return 0;
}

