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
//    void push(const T& element) {
//        Node* newNode = new Node(element);
//        newNode->next = topNode;
//        topNode = newNode;
//    }
//
//    void pop() {
//        if (isEmpty()) {
//            cout << "Error: Stack is empty. Cannot pop." << endl;
//            return;
//        }
//        Node* temp = topNode;
//        topNode = topNode->next;
//        delete temp;
//    }
//
//     T top() const {
//        if (isEmpty()) {
//            throw runtime_error("error: stack is empty. cannot retrieve top element.");
//        }
//        return topNode->data;
//    }
//
//    bool isEmpty() const {
//        return topNode == nullptr;
//    }
//
//    ~Stack() {
//        while (!isEmpty()) {
//            pop();
//        }
//    }
//};
//bool isPalindrome(const string& input) {
//    Stack<char> charStack;
//
//    // Push characters onto the stack
//    int n = input.size();
//    for (int i = 0; i < n; i++) {
//        charStack.push(input[i]);
//    }
//
//    // Compare characters with the popped characters from the stack
//    for (int i = 0; i < n; i++) {
//        char c = input[i];
//        if (c != charStack.top()) {
//            cout << input<<" is not a palindrome" << endl;
//            return 0;// Not a palindrome
//        }
//        charStack.pop();
//    }
//
//    cout << input <<" is is a palindrome" << endl;
//    return 0;
//}
//
//
//int main() {
//    string input1 = "racecar";
//    string input2 = "hello";
//    string input3 = "abba";
//    isPalindrome(input1);
//    isPalindrome(input2) ;
//    isPalindrome(input3);
//}