//#include <iostream>
//using namespace std;
//
//template <class T>
//class SortedSet {
//	struct Node {
//		T data;
//		Node* next;
//
//		Node(const T& value) : data(value), next(NULL) {}
//	};
//
//	Node* head;
//	Node* tail;
//
//public:
//	SortedSet() : head(NULL), tail(NULL) {}
//
//	void insert(T const data)
//	{
//		Node* n = new Node(data);
//		Node* temp;
//		if (head == NULL)
//		{
//			head = n;
//			tail = n;
//			return;
//		}
//		temp = head;
//		while (temp != NULL)
//		{
//			if (n->data < head->data)
//			{
//				n->next = head;
//				head = n;
//				return;
//			}
//			if (tail->data < n->data)
//			{
//				tail->next = n;
//				tail = n;
//			}
//			if (n->data > temp->data)
//			{
//				if (n->data < temp->next->data && temp->next != NULL)
//				{
//					n->next = temp->next;
//					temp->next = n;
//					return;
//				}
//			}
//			if (temp->next == NULL)
//			{
//				tail = temp;
//			}
//			temp = temp->next;
//		}
//	}
//
//	void Delete(int const index)
//	{
//		int counter = 0;
//		Node* temp = head;
//		Node* todelete;
//		while (temp != NULL)
//		{
//			if (counter == index && head == temp)
//			{
//				head = temp->next;
//				delete temp;
//				temp = NULL;
//				return;
//			}
//			if (counter + 2 == index && tail == temp->next)
//			{
//				tail = temp;
//				temp = temp->next;
//				tail->next = NULL;
//				delete temp;
//				temp = NULL;
//				return;
//			}
//			if (counter + 1 == index)
//			{
//				todelete = temp->next;
//				temp->next = temp->next->next;
//				delete todelete;
//				todelete = NULL;
//			}
//			temp = temp->next;
//			counter++;
//		}
//	}
//
//	void print() const
//	{
//		Node* temp = head;
//
//		while (temp != NULL)
//		{
//			cout << temp->data << "->";
//			temp = temp->next;
//		}
//		cout << endl;
//	}
//
//	void Union(SortedSet<T> const& otherSet)
//	{
//		Node* temp1 = head;
//		Node* temp2 = otherSet.head;
//		Node* newHead = nullptr;
//		Node* current = nullptr;
//
//		while (temp1 != nullptr || temp2 != nullptr)
//		{
//			Node* newNode = nullptr;
//
//			if (temp1 == nullptr)
//			{
//				newNode = new Node(temp2->data);
//				temp2 = temp2->next;
//			}
//			else if (temp2 == nullptr)
//			{
//				newNode = new Node(temp1->data);
//				temp1 = temp1->next;
//			}
//			else if (temp1->data < temp2->data)
//			{
//				newNode = new Node(temp1->data);
//				temp1 = temp1->next;
//			}
//			else if (temp1->data > temp2->data)
//			{
//				newNode = new Node(temp2->data);
//				temp2 = temp2->next;
//			}
//			else
//			{
//				newNode = new Node(temp1->data); // To handle duplicates, choose data from one set.
//				temp1 = temp1->next;
//				temp2 = temp2->next;
//			}
//
//			if (newHead == nullptr)
//			{
//				newHead = newNode;
//				current = newHead;
//			}
//			else
//			{
//				current->next = newNode;
//				current = current->next;
//			}
//		}
//
//		// Clean up the old set and update head and tail.
//		while (head != nullptr)
//		{
//			Node* toDelete = head;
//			head = head->next;
//			delete toDelete;
//		}
//
//		head = newHead;
//		tail = current;
//	}
//
//	void rotate(int k)
//	{
//		if (k < 0)
//		{
//			cout << "Entered number is incorrect";
//		}
//		if (k == 0)
//		{
//			return;
//		}
//		if (k > 1)
//		{
//			int counter = 1;
//			Node* temp = head;
//			{
//				tail->next = head;
//				while (temp != NULL)
//				{
//					if (counter == k)
//					{
//						tail = temp;
//						head = temp->next;
//						temp->next = NULL;
//						return;
//					}
//					temp = temp->next;
//					counter++;
//				}
//			}
//
//		}
//	}
//	void reverselist()
//	{
//		if (head == nullptr || head->next == nullptr)
//		{
//			return;
//		}
//
//		Node* prev = nullptr;
//		Node* current = head;
//		Node* next = nullptr;
//
//		while (current != nullptr)
//		{
//			next = current->next;
//			current->next = prev;
//			prev = current;
//			current = next;
//		}
//
//		tail = head;
//		head = prev;
//	}
//	~SortedSet()
//	{
//		Node* temp = head;
//		while (temp)
//		{
//			Node* todelete = temp;
//			temp = temp->next;
//			delete todelete;
//		}
//		head = nullptr;
//		tail = nullptr;
//	}
//};
//
//
//int main()
//{
//	SortedSet<int> a;
//	a.insert(2);
//	a.insert(1);
//	a.insert(5);
//	a.insert(3);
//	a.insert(4);
//	a.insert(8);
//	a.insert(6);
//	a.insert(7);
//	a.insert(10);
//	a.insert(11);
//	a.insert(10);
//	a.insert(11);
//	cout << "After inserting in A" << endl;
//	a.print();
//	cout << endl;
//	a.Delete(0);
//	a.Delete(7);
//	a.Delete(5);
//	a.Delete(4);
//	cout << "After deleting in A" << endl;
//	a.print();
//	cout << endl;
//	SortedSet<int> b;
//	b.insert(2);
//	b.insert(9);
//	b.insert(7);
//	b.insert(5);
//	b.insert(10);
//	b.insert(10);
//	cout << "After inserting in A" << endl;
//	b.print();
//	cout << endl;
//	a.Union(b);
//	cout << "After union of B with A" << endl;
//	a.print();
//	cout << endl;
//	cout << "Enter ";
//	int nnn;
//	cin >> nnn;
//	a.rotate(nnn);
//	cout << "After rotation" << endl;
//	a.print();
//	cout << endl;
//	a.reverselist();
//	cout << "After reversing A" << endl;
//	a.print();
//	cout << endl;
//	cout << "B print:" << endl;
//	b.print();
//	cout << endl;
//}