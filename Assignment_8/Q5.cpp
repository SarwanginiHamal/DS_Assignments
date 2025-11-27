#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool ascending) {
    int largestOrSmallest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (ascending) {
        if (left < n && arr[left] > arr[largestOrSmallest])
            largestOrSmallest = left;
        if (right < n && arr[right] > arr[largestOrSmallest])
            largestOrSmallest = right;
    } else {
        if (left < n && arr[left] < arr[largestOrSmallest])
            largestOrSmallest = left;
        if (right < n && arr[right] < arr[largestOrSmallest])
            largestOrSmallest = right;
    }

    if (largestOrSmallest != i) {
        swap(arr[i], arr[largestOrSmallest]);
        heapify(arr, n, largestOrSmallest, ascending);
    }
}
void heapSort(int arr[], int n, bool ascending = true) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, ascending);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);  
        heapify(arr, i, 0, ascending); 
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int choice;
    cout << "Heap Sort Order:\n1. Ascending\n2. Descending\nEnter choice: ";
    cin >> choice;
    bool ascending = (choice == 1);
    heapSort(arr, n, ascending);
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
