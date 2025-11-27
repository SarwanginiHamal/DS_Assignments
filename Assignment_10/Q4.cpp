#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    int firstNonRepeating = -1; 
    for (int num : nums) {
        if (freq[num] == 1) {
            firstNonRepeating = num;
            break;
        }
    }
    if (firstNonRepeating != -1)
        cout << "First non-repeating element: " << firstNonRepeating << endl;
    else
        cout << "No non-repeating element found." << endl;
    return 0;
}
