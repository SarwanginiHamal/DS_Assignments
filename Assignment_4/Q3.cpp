#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue has odd number of elements. Interleaving not possible." << endl;
        return;
    }

    int half = q.size() / 2;
    stack<int> s;

    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9}; 
    for (int v : arr) q.push(v);

    interleaveQueue(q);

    cout << "Output: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
