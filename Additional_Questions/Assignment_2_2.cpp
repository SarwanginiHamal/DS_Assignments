#include <iostream>
#include <string>
using namespace std;

bool canSplit(string s) {
    int n = s.length();
    for (int len = 1; len <= n - 2; len++) { 
        for (int i = 0; i <= n - len; i++) {
            string common = s.substr(i, len); 
            for (int j = 1; j <= n - 2; j++) {
                for (int k = j + 1; k <= n - 1; k++) {
                    string part1 = s.substr(0, j);
                    string part2 = s.substr(j, k - j);
                    string part3 = s.substr(k);
                    int count = 0;
                    if (part1.find(common) != string::npos) count++;
                    if (part2.find(common) != string::npos) count++;
                    if (part3.find(common) != string::npos) count++;
                    if (count >= 2) return true; 
                }
            }
        }
    }
    return false;
}
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    if (canSplit(s))
        cout << "Yes, it's possible to split the string." << endl;
    else
        cout << "No, it's not possible to split the string." << endl;
    return 0;
}
