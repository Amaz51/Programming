//#include<iostream>
//using namespace std;
//template <typename T>
//struct Node {
//	int data;
//	Node* next;
//	Node(int d) {
//		data = d;
//		next = NULL;
//	}
//};
//template<typename T> 
//class Queue {
//	Node<T>* top;
//	Node<T>* bottom;
//	int size;
//public:
//	Queue() {
//		size = 0;
//		top = NULL;
//		bottom = NULL;
//	}
//	bool Isempty() {
//		if (size == 0) {
//			return 1;
//
//		}return 0;
//	}
//	bool enque(const T d) {
//		Node<T>* neww = new Node(d);
//		if (Isempty()) {
//			top = bottom = neww;
//		}
//		else if (top == bottom) {
//			bottom->next = newNode;
//			head = newNode;
//		}
//		else {
//			top->next = newNode;
//			top = newNode;
//		}return 1;
//	}
//	bool dequeue(T & d) {
//		if (!Isempty()) {
//			Node* temp = bottom;
//			if (bottom->next != NULL) {
//				bottom = bottom->next;
//			}delete temp;
//			return 1;
//		}
//	}
//	void print() {
//		Node<T>* temp = bottom;
//		for (; temp != NULL;) {
//			cout << temp->data << " ";
//			temp = temp->next;
//		}cout << endl;
//	}
//};
//class Book {
//	int ISBN;
//	bool avail;
//	string title;
//	string author;
//public:
//	Book():ISBN(0),avail(0),title(""),author("") {
//	}
//	Book(int ib, bool ava, string tit, string aut) {
//		ISBN = ib;
//		ava = avail;
//
//	}
//	
//};
//class patron {
//	int id; 
//	string name;
//	string reserved;
//public:
//
//}; 
//int main() {
//	Queue<int> q;
//	q.enque(1);
//	q.enque(2);
//	q.enque(3);
//	q.print();
//	q.dequeue();
//	q.print();
//}