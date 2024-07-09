//#include <iostream>
//
//using namespace std;
//
//struct StackNode {
//    int data;
//    StackNode* next;
//};
//
//class Stack {
//private:
//    StackNode* top;
//
//public:
//    Stack() { top = nullptr; }
//
//    bool isEmpty() { return top == nullptr; }
//
//    void push(int data) {
//        StackNode* newNode = new StackNode;
//        newNode->data = data;
//        newNode->next = top;
//        top = newNode;
//    }
//
//    int pop() {
//        if (isEmpty()) {
//            cerr << "Stack is empty" << endl;
//            return -1;
//        }
//
//        int data = top->data;
//        StackNode* temp = top;
//        top = top->next;
//        delete temp;
//        return data;
//    }
//
//    void deleteLastElement() {
//        if (isEmpty()) {
//            return;
//        }              
//        if (top->next == nullptr) {//delete if stack has only 1 ele
//            delete top;
//            top = nullptr;
//            return;
//        }               
//        StackNode* prev = nullptr;
//        StackNode* curr = top;
//
//        while (curr->next->next != nullptr) {
//            prev = curr;
//            curr = curr->next;
//        }
//        delete curr->next;
//        curr->next = nullptr;
//    }
//
//    void printStack() {
//        StackNode* curr = top;
//        while (curr != nullptr) {
//            cout << curr->data << " ";
//            curr = curr->next;
//        }
//        cout << endl;
//    }
//    bool is_balanced(string expr) {
//        Stack stack;
//        for (char c : expr) {
//            if (c == '(' || c == '{' || c == '[') {
//                stack.push(c);
//            }
//            else if (c == ')' || c == '}' || c == ']') {
//                if (stack.isEmpty()) {
//                    return false;
//                }
//                char opening_bracket = stack.pop();
//                if (opening_bracket != c - 1 && opening_bracket != c - 2) {
//                    return false;
//                }
//            }
//        }
//        return stack.isEmpty();
//    }
//};
//
//int main() {
//    Stack s;
//    s.push(1);
//    s.push(2);
//    s.push(3);
//    s.push(4);
//    s.push(5);
//
//    cout << "Stack before deleting last element: ";
//    s.printStack();
//
//    s.deleteLastElement();
//
//    cout << "Stack after deleting last element: ";
//    s.printStack();
//    string expr = "(a + b} * (c + d)";
//    if (s.is_balanced(expr)) {
//        cout << "The expression is balanced." << endl;
//    }
//    else {
//        cout << "The expression is not balanced." << endl;
//    }
//    return 0;
//}