#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countStudentsUnableToEat(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);
    int n = sandwiches.size();
    int index = 0; 
    int rotations = 0;
    while (!q.empty() && rotations < q.size()) {
        if (q.front() == sandwiches[index]) {
            q.pop();    
            index++;     
            rotations = 0; 
        } else {
            int temp = q.front();
            q.pop();
            q.push(temp);
            rotations++;
        }
    }
    return q.size();
}
int main() {
    int n;
    cout << "Enter number of students/sandwiches: ";
    cin >> n;
    vector<int> students(n), sandwiches(n);
    cout << "Enter student preferences (0 for circular, 1 for square): ";
    for (int i = 0; i < n; i++) cin >> students[i];
    cout << "Enter sandwiches stack (top to bottom) (0 for circular, 1 for square): ";
    for (int i = 0; i < n; i++) cin >> sandwiches[i];
    int unableToEat = countStudentsUnableToEat(students, sandwiches);
    cout << "Number of students unable to eat: " << unableToEat << endl;
    return 0;
}
