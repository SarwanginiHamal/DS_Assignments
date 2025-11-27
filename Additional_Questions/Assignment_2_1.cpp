#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countPairsWithDifferenceK(const vector<int>& arr, int k) {
    unordered_set<int> seen;
    int count = 0;

    for (int num : arr) {
        if (seen.find(num + k) != seen.end()) count++;
        if (seen.find(num - k) != seen.end()) count++;
        seen.insert(num);
    }
    return count;
}
int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the value of k: ";
    cin >> k;
    int totalPairs = countPairsWithDifferenceK(arr, k);
    cout << "Number of pairs with difference " << k << ": " << totalPairs << endl;
    return 0;
}
