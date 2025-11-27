#include <iostream>
#include <vector>
using namespace std;

void duplicateTwos(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    int count2 = 0;
    for (int j = 0; j < n; j++) {
        if (arr[j] == 2) count2++;
    }
    int newLength = n + count2;
    for (int j = n - 1; j >= 0; j--) {
        if (j + count2 < n) arr[j + count2] = arr[j]; 
        if (arr[j] == 2) {
            count2--;
            if (j + count2 < n) arr[j + count2] = 2; 
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    duplicateTwos(arr);
    cout << "Modified array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}
