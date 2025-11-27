#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    for (auto& pair : freq) {
        cout << "• " << pair.first << " → " << pair.second 
             << " " << (pair.second > 1 ? "times" : "time") << endl;
    }
    return 0;
}
