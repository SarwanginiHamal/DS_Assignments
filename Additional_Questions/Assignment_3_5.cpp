#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool canSortWithStack(vector<int> A) {
    stack<int> S;
    int expected = 1; 
    int n = A.size();
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    int idx = 0; 
    while (!A.empty() || !S.empty()) {
        if (!S.empty() && S.top() == sortedA[idx]) {
            S.pop();
            idx++;
        }
        else if (!A.empty() && A[0] == sortedA[idx]) {
            A.erase(A.begin());
            idx++;
        }
        else if (!A.empty()) {
            S.push(A[0]);
            A.erase(A.begin());
        }
        else {
            return false;
        }
    }

    return true;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter elements of A: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    if (canSortWithStack(A))
        cout << "Yes, it is possible to sort array B using stack operations." << endl;
    else
        cout << "No, it is not possible." << endl;
    return 0;
}
