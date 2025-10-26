#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;
    for(char ch : expr) {
        if(isdigit(ch)) {
            st.push(ch - '0'); 
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch(ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands): ";
    cin >> postfix;
    cout << "Evaluated value: " << evaluatePostfix(postfix) << endl;
    return 0;
}
