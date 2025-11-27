#include <bits/stdc++.h>
using namespace std;

bool arraysEqual(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    unordered_map<int,int> cnt;
    for (int x : a) cnt[x]++;
    for (int x : b) {
        if (!cnt.count(x) || cnt[x] == 0) return false;
        cnt[x]--;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    cout << (arraysEqual(a, b) ? "true" : "false") << "\n";
    return 0;
}
