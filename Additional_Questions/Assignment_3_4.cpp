#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(const vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0); 
    stack<int> s; 
    for (int i = 0; i < n; i++) {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            int idx = s.top();
            s.pop();
            answer[idx] = i - idx; 
        }
        s.push(i);
    }
    return answer;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    vector<int> temperatures(n);
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++)
        cin >> temperatures[i];
    vector<int> answer = dailyTemperatures(temperatures);
    cout << "Days to wait for warmer temperature: ";
    for (int days : answer)
        cout << days << " ";
    cout << endl;
    return 0;
}
