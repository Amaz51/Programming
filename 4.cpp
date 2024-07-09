//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T>
//class Stack {
//private:
//    struct Node {
//        T data;
//        Node* next;
//
//        Node(const T& item) {
//            data = item;
//            next = nullptr;
//        }
//    };
//
//    Node* topNode;
//
//public:
//    Stack() {
//        topNode = nullptr;
//    }
//
//
//    void push(const T& element) {// Push an element onto the stack
//        Node* newNode = new Node(element);
//        newNode->next = topNode;
//        topNode = newNode;
//    }
//
//
//    void pop() {// Pop the top element
//        if (isEmpty()) {
//            cout << "As stack is empty,cant pop." << endl;
//            return;
//        }
//        Node* temp = topNode;
//        topNode = topNode->next;
//        delete temp;
//    }
//
//
//    T top() const {
//        if (isEmpty()) {
//            return -1;
//        }
//        return topNode->data;
//    }
//
//    // Check if the stack is empty
//    bool isEmpty() const {
//        return topNode == nullptr;
//    }
//
//    // Destructor to deallocate memory
//    ~Stack() {
//        while (!isEmpty()) {
//            pop();
//        }
//    }
//};
//
//// Function to check if a character is an operator (+, -, *, /)
//bool isOperator(char c) {
//    return c == '+' || c == '-' || c == '*' || c == '/';
//}
//
//// Function to determine the precedence of an operator
//int precedence(char c) {
//    if (c == '+' || c == '-') {
//        return 1;
//    }
//    else if (c == '*' || c == '/') {
//        return 2;
//    }
//    return 0;
//}
//
//// Function to convert an infix expression to a prefix expression
//string infixToPrefix(const string& infix) {
//    Stack<char> operators;      // Stack to hold operators
//    Stack<string> operands;    // Stack to hold operands
//
//    for (int i = 0; i < infix.length(); i++) {
//        char c = infix[i];     // Loop through each character in the infix expression
//        if (isalnum(c)) {       // If the character is an alphanumeric character (operand)
//            operands.push(string(1, c));  // Push it as a string onto the operands stack
//        }
//        else if (c == '(') {  // If the character is an opening parenthesis
//            operators.push(c);  // Push it onto the operators stack
//        }
//        else if (c == ')') {  // If the character is a closing parenthesis
//            while (!operators.isEmpty() && operators.top() != '(') {
//                // Pop two operands and an operator, concatenate them, and push the result as an operand
//                string op2 = operands.top();
//                operands.pop();
//                string op1 = operands.top();
//                operands.pop();
//                char oper = operators.top();
//                operators.pop();
//                string temp = oper + op1 + op2;
//                operands.push(temp);
//            }
//            operators.pop(); // Pop and discard the opening parenthesis
//        }
//        else if (isOperator(c)) { // If the character is an operator
//            while (!operators.isEmpty() && operators.top() != '(' &&
//                precedence(c) <= precedence(operators.top())) {
//                // Pop two operands and an operator, concatenate them, and push the result as an operand
//                string op2 = operands.top();
//                operands.pop();
//                string op1 = operands.top();
//                operands.pop();
//                char oper = operators.top();
//                operators.pop();
//                string temp = oper + op1 + op2;
//                operands.push(temp);
//            }
//            operators.push(c); // Push the current operator onto the operators stack
//        }
//    }
//
//    // Process any remaining operators on the stack
//    while (!operators.isEmpty()) {
//        // Pop two operands and an operator, concatenate them, and push the result as an operand
//        string op2 = operands.top();
//        operands.pop();
//        string op1 = operands.top();
//        operands.pop();
//        char oper = operators.top();
//        operators.pop();
//        string temp = oper + op1 + op2;
//        operands.push(temp);
//    }
//
//    // The top of the operands stack will contain the final prefix expression
//    return operands.top();
//}
//
//int main() {
//    string infixExpression1 = "(A + B) * (C + D)";
//    string infixExpression2 = "A + B + C + D";
//    string infixExpression3 = "A + B * C ";
//
//    cout << "Infix Expression is: " << infixExpression1 << endl;
//    cout << "Prefix Expression is: " << infixToPrefix(infixExpression1) << endl;
//
//    cout << "Infix Expression is: " << infixExpression2 << endl;
//    cout << "Prefix Expression is: " << infixToPrefix(infixExpression2) << endl;
//
//    cout << "Infix Expression is: " << infixExpression3 << endl;
//    cout << "Prefix Expression is: " << infixToPrefix(infixExpression3) << endl;
//
//    return 0;
//}