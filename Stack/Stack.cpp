#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std;

const int MAX_STACK_SIZE = 5;
int stackArray[MAX_STACK_SIZE] = {-1, -1, -1, -1, -1};
int topOfStack = -1;

void Push(int);
void Pop();
void Peek();
bool IsFull();
bool IsEmpty();
void ViewStack();

int main()
{
    string again = "";
    bool cont = false;
    int userInput;
    int pushNum;
    do {
        system("CLS");
        cout << "What function would you like to run? \n1 - Push \n2-Pop \n3-Peek \n4-IsFull \n5-IsEmpty \n6-View Stack \n0-Quit" << endl;
        cin >> userInput;

        switch (userInput) {
        case 1:
            cin.clear();
            cout << "Please enter a number to push: ";
            cin >> pushNum;
            Push(pushNum);
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            IsFull();
            break;
        case 5:
            IsEmpty();
            break;
        case 6: 
            ViewStack();
            break;
        case 0:
            return 1;
        default:
            break;
        }

        cin.clear();
        cout << "Would you like to perform another function?(y/n): ";
        cin >> again;
        cont = again == "y" || again == "Y" ? true : false;
    } while (cont);

    return 1;
}

void Push(int x) {
    if (topOfStack == MAX_STACK_SIZE - 1) {
        cout << "Cannot push to a full stack!" << endl;
    }
    else {
        topOfStack++;
        stackArray[topOfStack] = x;
        cout << "Pushed " << x << " onto the stack!" << endl;
    }
}

void Pop() {
    if (topOfStack < 0) {
        cout << "Cannot pop from an empty stack!" << endl;
    }
    else {
        int x = stackArray[topOfStack];
        stackArray[topOfStack] = 0;
        topOfStack--;
        cout << "Popped " << x << " off the stack!" << endl;
    }
}

void Peek() {
    if (topOfStack < 0) {
        cout << "Stack is empty! " << endl;
    }
    else {
        cout << "Top of stack: " << stackArray[topOfStack] << endl;
    }
}

bool IsFull() {
    if (topOfStack == MAX_STACK_SIZE - 1) {
        cout << "Stack is full!" << endl;
        return true;
    }
    else {
        return false;
    }
}

bool IsEmpty() {
    if (topOfStack < 0) {
        cout << "Stack is empty!" << endl;
        return true;
    }
    else {
        return false;
    }
    
}

void ViewStack() {
    if (topOfStack < 0) {
        cout << "Stack is empty!" << endl;
    }
    else {
        cout << endl;
        for (int i = topOfStack; i > -1; i--) {
            cout << " " << stackArray[i] << " " << endl;
            cout << "---" << endl;
        }
    }
}

