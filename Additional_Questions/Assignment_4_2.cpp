#include <iostream>
#include <queue>
using namespace std;

int queueSize(queue<int>& q) {
    return q.size();
}

int findAndRemoveMin(queue<int>& q, int n) {
    int minVal = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x = q.front();
        q.pop();
        if (x < minVal) {
            minVal = x;
        }
        q.push(x);
    }
    for (int i = 0; i < n; i++) {
        int x = q.front();
        q.pop();
        if (x != minVal) {
            q.push(x);
        } else {
            break; 
        }
    }
    return minVal;
}
void sortQueue(queue<int>& q) {
    int n = queueSize(q);

    for (int i = 0; i < n; i++) {
        int size = n - i; 
        int minVal = findAndRemoveMin(q, size);
        q.push(minVal); 
    }
}
int main() {
    queue<int> q;
    int n, val;
    cout << "Enter number of elements in queue: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }
    sortQueue(q);
    cout << "Sorted queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
