#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerToLeft(const vector<int>& arr) {
    vector<int> result;
    stack<int> s;
    for (int num : arr) {
        while (!s.empty() && s.top() >= num) {
            s.pop();
        }
        if (s.empty())
            result.push_back(-1); 
        else
            result.push_back(s.top()); 
        s.push(num); 
    }
    return result;
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> result = nearestSmallerToLeft(arr);
    cout << "Nearest smaller elements to the left: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;
    return 0;
}
