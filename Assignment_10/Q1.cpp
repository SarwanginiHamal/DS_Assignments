#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true; 
        }
        seen.insert(num);
    }
    return false; 
}
int main() {
    vector<int> nums = {1, 2, 3, 1};
    if (containsDuplicate(nums))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
