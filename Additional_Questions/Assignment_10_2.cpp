#include <bits/stdc++.h>
using namespace std;

bool hasPairWithSum(const vector<int>& arr, int target) {
    unordered_set<int> s;
    for (int x : arr) {
        if (s.count(target - x)) return true;
        s.insert(x);
    }
    return false;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << (hasPairWithSum(arr, target) ? "true" : "false") << "\n";
    return 0;
}
