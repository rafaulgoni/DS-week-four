// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
//     stack<int> s;
//     queue<int> q;

//     for (int i = 0; i < n; ++i) {
//         int value;
//         cin >> value;
//         s.push(value);
//     }

//     for (int i = 0; i < m; ++i) {
//         int value;
//         cin >> value;
//         q.push(value);
//     }

//     bool same = true;
//     while (!s.empty() && !q.empty()) {
//         if (s.top() != q.front()) {
//             same = false;
//             break;
//         }
//         s.pop();
//         q.pop();
//     }

//     if (same && s.empty() && q.empty()) {
//         cout << "YES" << endl;
//     } else {
//         cout << "NO" << endl;
//     }

//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// bool isValid(string s) {
//     stack<char> st;
//     for (char c : s) {
//         if (c == '0') {
//             if (!st.empty() && st.top() == '1') {
//                 st.pop();
//             } else {
//                 st.push(c);
//             }
//         } else if (c == '1') {
//             if (!st.empty() && st.top() == '0') {
//                 st.pop();
//             } else {
//                 st.push(c);
//             }
//         }
//     }
//     return st.empty();
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         string s;
//         cin >> s;
//         if (isValid(s)) {
//             cout << "YES" << endl;
//         } else {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int q;
//     cin >> q;
//     queue<string> line;

//     while (q--) {
//         int command;
//         cin >> command;
//         if (command == 0) {
//             string name;
//             cin >> name;
//             line.push(name);
//         } else if (command == 1) {
//             if (!line.empty()) {
//                 cout << line.front() << endl;
//                 line.pop();
//             } else {
//                 cout << "Invalid" << endl;
//             }
//         }
//     }

//     return 0;
// }




#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Stack {
public:
    Node* top;
    Stack() : top(NULL) {}

    void push(int value) {
        Node* newNode = new Node(value);
        if (top != NULL) {
            top->next = newNode;
            newNode->prev = top;
        }
        top = newNode;
    }

    int pop() {
        if (top == NULL) return -1;
        int value = top->val;
        Node* temp = top;
        top = top->prev;
        if (top != NULL) {
            top->next = NULL;
        }
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == NULL;
    }

    int peek() {
        if (top == NULL) return -1;
        return top->val;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;
    Queue() : front(NULL), rear(NULL) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == NULL) return -1;
        int value = front->val;
        Node* temp = front;
        front = front->next;
        if (front != NULL) {
            front->prev = NULL;
        } else {
            rear = NULL;
        }
        delete temp;
        return value;
    }

    bool isEmpty() {
        return front == NULL;
    }

    int peek() {
        if (front == NULL) return -1;
        return front->val;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Stack s;
    Queue q;

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        s.push(value);
    }

    for (int i = 0; i < m; ++i) {
        int value;
        cin >> value;
        q.enqueue(value);
    }

    bool same = true;
    while (!s.isEmpty() && !q.isEmpty()) {
        if (s.peek() != q.peek()) {
            same = false;
            break;
        }
        s.pop();
        q.dequeue();
    }

    if (same && s.isEmpty() && q.isEmpty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
