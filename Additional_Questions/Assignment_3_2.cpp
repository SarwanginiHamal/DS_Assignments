#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> st;
    long long minElement;
public:
    MinStack() {}
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            minElement = x;
        } else {
            if (x < minElement) {
                st.push(2LL*x - minElement);
                minElement = x;
            } else {
                st.push(x);
            }
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        long long top = st.top();
        st.pop();
        if (top < minElement) {
            minElement = 2*minElement - top;
        }
    }
    int top() {
        if (st.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        long long top = st.top();
        return (top < minElement) ? minElement : top;
    }
    int getMin() {
        if (st.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return minElement;
    }
    bool empty() {
        return st.empty();
    }
};
int main() {
    MinStack s;
    int choice, val;
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Get Min\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.top() << endl;
                break;
            case 4:
                cout << "Minimum element: " << s.getMin() << endl;
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
