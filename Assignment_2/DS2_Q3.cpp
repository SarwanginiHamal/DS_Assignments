#include<bits/stdc++.h>
using namespace std;


int findMissingNumberlt(vector<int> &arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n;
}

// Using Binary Search
int findMissingNumberbs(vector<int> &arr, int n) {
    int low = 0, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low + 1;
}


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    cout << findMissingNumberlt(nums, n) << endl;
    cout << findMissingNumberbs(nums, n) << endl;
    return 0;
}
