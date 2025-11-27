#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }
    void heapifyDown(int index) {
        int n = heap.size();
        while (2 * index + 1 < n) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    int extractMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }
    int getMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }
    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;
    while (true) {
        cout << "\nPriority Queue Operations:\n";
        cout << "1. Insert\n2. Extract Max\n3. Peek Max\n4. Display Heap\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                value = pq.extractMax();
                if (value != -1)
                    cout << "Extracted Max: " << value << endl;
                break;
            case 3:
                value = pq.getMax();
                if (value != -1)
                    cout << "Maximum Element: " << value << endl;
                break;
            case 4:
                cout << "Heap: ";
                pq.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
