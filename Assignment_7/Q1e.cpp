#include <iostream>
using namespace std;

class QuickSort {
private:
    int arr[100];
    int n;
    int partition(int low, int high) {
        int pivot = arr[high];  
        int i = low - 1;       
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }
    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high); 
            quickSort(low, pi - 1);  
            quickSort(pi + 1, high);
        }
    }
public:
    void input() {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void sortArray() {
        quickSort(0, n - 1);
    }

    void display() {
        cout << "\nSorted Array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    QuickSort q;
    q.input();
    q.sortArray();
    q.display();
    return 0;
}
