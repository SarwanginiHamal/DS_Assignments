#include <bits/stdc++.h>
using namespace std;

int mostFrequentLargest(const vector<int>& arr) {
    unordered_map<int,int> freq;
    for (int x : arr) freq[x]++;

    int bestVal = INT_MIN, bestFreq = 0;
    for (auto &p : freq) {
        int val = p.first, f = p.second;
        if (f > bestFreq || (f == bestFreq && val > bestVal)) {
            bestFreq = f;
            bestVal = val;
        }
    }
    return bestVal;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << mostFrequentLargest(arr) << "\n";
    return 0;
}
