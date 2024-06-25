#include<iostream>
using namespace std;


template <typename T>
class SortedSet {
private:
	struct node {
		T data;
		node* next;
		node(const T& val) {
			data = val;
			next = NULL;
		}
	};
	node* head;
	node* tail;
public:
	//Q1
	//construtor
	SortedSet() {
		head = NULL;
		tail = NULL;
	}
	//INSERTION
	void insert(T const data)
	{
		node* neww = new node(data);
		if (!head) {
			head = neww;
			tail = neww;
			return;
		}
		node* temp = head;
		while (temp) {
			int h = head->data;
			int t = tail->data;
			int tempp = temp->data;
			if (h > neww->data)
			{
				neww->next = head;
				head = neww;
				return;
			}
			if (t < neww->data)
			{
				tail->next = neww;
				tail = neww;
			}
			if (tempp < neww->data && temp->next && neww->data < temp->next->data)
			{
				neww->next = temp->next;
				temp->next = neww;
				return;
			}
			if (!(temp->next))
			{
				tail = temp;
			}
			temp = temp->next;
		}
	}

	//DELETION
	void Delete(int const ind)
	{
		int k = 0;
		node* temp = head;
		node* todel;
		while (temp)
		{
			if (k == ind && head == temp) {
				head = temp->next;
				delete temp;
				temp = NULL;
				return;
			}
			if (k + 2 == ind && tail == temp->next) {
				tail = temp;
				temp = temp->next;
				tail->next = NULL;
				delete temp;
				temp = NULL;
				return;
			}
			if (k + 1 == ind) {
				todel = temp->next;
				temp->next = temp->next->next;
				delete todel;
				todel = NULL;
			}
			temp = temp->next;
			k++;
		}
	}
	//UNION
	void Union(SortedSet<T> const& otherSet)
	{
		node* t1 = head;
		node* t2 = otherSet.head;
		node* newHead = nullptr;
		node* curr = nullptr;

		while (t1 || t2)
		{
			node* newNode = NULL;

			if (!t1) {
				newNode = new node(t2->data);
				t2 = t2->next;
			}
			else if (!t2) {
				newNode = new node(t1->data);
				t1 = t1->next;
			}
			else if (t1->data < t2->data) {
				newNode = new node(t1->data);
				t1 = t1->next;
			}
			else if (t1->data > t2->data) {
				newNode = new node(t2->data);
				t2 = t2->next;
			}
			else {
				newNode = new node(t1->data);
				t1 = t1->next;
				t2 = t2->next;
			}

			if (!newHead) {
				newHead = newNode;
				curr = newHead;
			}
			else {
				curr->next = newNode;
				curr = curr->next;
			}
		}
		while (head)
		{
			node* todel = head;
			head = head->next;
			delete todel;
		}

		head = newHead;
		tail = curr;
	}
	//ROTATION
	void Rotate(int k) {

		node* curr = head;
		for (int i = 0; i < k - 1; i++) {
			curr = curr->next;
		}
		tail->next = head;
		head = curr->next;
		curr->next = NULL;
		tail = curr;
	}
	//REVERSE
	void reverse() {
		if (head == nullptr || head->next == nullptr) { return; }
		node* prev = NULL;
		node* curr = head;
		node* nextptr = NULL;

		while (curr != NULL) {
			nextptr = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextptr;
		}
		head = prev;
	}
	//PRINT
	void display() {
		node* curr = head;
		while (curr) {
			cout << curr->data << "->";
			curr = curr->next;
		}cout << "NULL" << endl;
	}
	//DESTRUCTOR
	~SortedSet()
	{
		node* temp = head;
		while (temp)
		{
			node* todel = temp;
			temp = temp->next;
			delete todel;
		}
		head = NULL;
		tail = NULL;
	}
};



int main()
{		//Insertion
	SortedSet<int> list1;
	cout << "\t\t\t\t\t\t" << "Question 1 " << '\t' << endl;
	list1.insert(3);
	list1.insert(20);
	list1.insert(50);
	list1.insert(30);
	list1.insert(10);
	list1.insert(25);
	list1.insert(40);
	list1.insert(60);
	list1.insert(70);
	list1.insert(60);


	cout << "\t\t\t" << "Insertion in List 1 " << '\t' << endl << endl;

	//Displaying list 1
	list1.display();
	cout << endl;

	//Deletion of some elements
	list1.Delete(3);
	list1.Delete(70);
	list1.Delete(25);

	
	cout << "\t\t\t" << "Deletion in list 1 " << '\t' << endl << endl;
	list1.display();
	cout << endl;

	//Insertion in list2
	SortedSet<int> list2;

	list2.insert(75);
	list2.insert(85);
	list2.insert(55);
	list2.insert(35);
	list2.insert(15);
	list2.insert(10);


	cout << "\t\t\t" << "Insertion in List 2 " << '\t' << endl << endl;
	list2.display();
	cout << endl;

	list1.Union(list2);
	//UNION
	cout << "\t\t\t" << "UNION of List 2 with List 1 " << '\t' << endl << endl;
	list1.display();
	cout << endl << "\t\t\t\t\t\t" << "Question 2 " << '\t' << endl << endl << "Enter the k nodes to be rotated : ";


	int nnn;
	cin >> nnn;
	if (nnn < 0) {
		cout << "Entered incorrect number.";
	}
	else {
	cout << endl;
	list1.Rotate(nnn);
	cout << "\t\t\t" << "ROTATION" << '\t' << endl << endl;
	list1.display();
	}


	list1.reverse();
	cout << endl << "\t\t\t\t\t\t" << "Question 3 " << '\t' << endl << endl << "\t\t\t" << "REVERSE" << '\t' << endl << endl;
	list1.display();


	cout << endl << "\t\t\t" << "Displaying B " << '\t' << endl << endl;
	list2.display();
}