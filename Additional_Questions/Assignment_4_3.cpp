#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

bool canSortQueueWithStack(queue<int> q) {
    stack<int> s;
    int expected = 1; 
    int n = q.size();
    while (!q.empty() || !s.empty()) {
        if (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        }
        else if (!q.empty() && q.front() == expected) {
            q.pop();
            expected++;
        }
        else if (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        else {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    queue<int> q;
    int val;
    cout << "Enter elements of the queue: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }
    if (canSortQueueWithStack(q))
        cout << "Yes, it is possible to arrange the queue in increasing order using a stack." << endl;
    else
        cout << "No, it is not possible." << endl;
    return 0;
}
