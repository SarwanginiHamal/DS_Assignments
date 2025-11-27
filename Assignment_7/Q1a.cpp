#include <iostream>
using namespace std;
class SelectionSort {
private:
    int arr[100];      
    int n;            
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
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;

            // Find index of minimum element
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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
    SelectionSort s;
    s.input();     
    s.sortArray();  
    s.display();   
    return 0;
}
