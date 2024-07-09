//#include<iostream>
//using namespace std;
//template <typename T>
//class Stack {
//private:
//    struct Node {
//        T data;
//        Node* next;
//    };
//
//    Node* top; 
//    int size; 
//
//public:
//    Stack() {
//        top = nullptr;
//        size = 0;
//    }
//
//    ~Stack() {
//        while (!isEmpty()) {
//            pop();
//        }
//    }
//   int sizee() {
//        return size;
//    }
//    bool isEmpty() {
//        return top == nullptr;
//    }
//    bool topp(T& element) {
//        if (isEmpty()) {
//            return false;
//        }
//
//        element = top->data;
//        return true;
//    }
//
//        void pop() {
//        if (isEmpty()) {
//            return;
//        }
//
//        Node* temp = top;
//        top = top->next;
//        delete temp;
//        size--;
//    }
//
//    void push(const T& element) {
//        Node* newNode = new Node();
//        newNode->data = element;
//        newNode->next = top;
//        top = newNode;
//        size++;
//    }
//    void Deletetail() {//task 2
//        Stack neww;
//        T element;
//        while (size != 0) {
//            topp(element);
//            pop();
//            neww.push(element);
//            
//        }
//        neww.pop();
//        while (neww.size() != 0) {
//            neww.topp(element);
//            neww.pop();
//            push(element);
//        }
//    }
//    
//};
//int main() {
//    Stack<int> stack;
//    stack.push(1);
//    stack.push(2);
//    stack.push(3);
//    int size = stack.sizee();
//
// 
//    int element;
//    if (stack.topp(element)) {
//       cout << "The top element is: " << element <<endl;
//    }
//
//    stack.pop();
//   
//    
//    if (stack.isEmpty()) {
//        cout << "The stack is empty." << endl;
//    }
//}