#include <iostream>
using namespace std;

class ImprovedSelectionSort {
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
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int minIndex = left;
            int maxIndex = right;
            if (arr[minIndex] > arr[maxIndex]) {
                swap(arr[minIndex], arr[maxIndex]);
            }
            for (int i = left + 1; i < right; i++) {
                if (arr[i] < arr[minIndex]) {
                    minIndex = i;
                }
                if (arr[i] > arr[maxIndex]) {
                    maxIndex = i;
                }
            }
            swap(arr[left], arr[minIndex]);
            if (maxIndex == left)  
                maxIndex = minIndex;
            swap(arr[right], arr[maxIndex]);
            left++;
            right--;
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
    ImprovedSelectionSort obj;
    obj.input();
    obj.sortArray();
    obj.display();
    return 0;
}
