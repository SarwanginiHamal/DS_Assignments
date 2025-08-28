#include <iostream>
using namespace std;
#define MAX 100


int stackArr[MAX];
int top;


void push(int value) {
    if (top >= MAX-1) {
    cout << "Stack is full\n"<<endl;
} else {
    top++;
    stackArr[top] = value;
}
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty\n";
    } else {
        cout << "Popped: " << stackArr[top] << "\n";
        top--;
    }
}

void isEmpty() {
    if (top == -1){
        cout << "Stack is empty\n";
    }
    else{
        cout << "Stack is not empty\n";
    }
            
}

void isFull() {
    if (top >= MAX-1)
        cout << "Stack is full\n";
    else
        cout << "Stack is not full\n";
}

void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
    } else {
        for (int i = top; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << "\n";
    }
}

void peek() {
    if (top == -1)
        cout << "Stack is empty\n";
    else
        cout << "Top element: " << stackArr[top] << "\n";
}


int main() {
    int choice, value;
    while (true) {
        cout<<"\nStack Operations Menu:\n";
        cout << "1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cin >> choice;
        switch(choice){
            case 1:
                cout<<"Enter Value to push:";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                isFull();
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                return 0;
            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
}
                
    
              
