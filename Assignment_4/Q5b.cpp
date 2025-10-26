#include <iostream>
#include <queue>
using namespace std;

class StackUsing1Queue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for(int i=0; i<(q.size()-1); i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if(q.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        q.pop();
    }
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsing1Queue s;
    s.push(10);
    s.push(20);
    cout << "Top: " << s.top() << endl; 
    s.pop();
    cout << "Top: " << s.top() << endl; 
    return 0;
}
