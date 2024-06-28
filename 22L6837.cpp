#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) {
            data = value;
            next = NULL;
        }
    };
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        else {

            cout << "Queue is empty ." << endl;
        }
    }

    T peek() const {
        if (!isEmpty()) {
            return front->data;
        }
        else {
            cout << "Queue is empty" << endl;
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

class Book {
    string isbn;
    string title;
    string author;
    bool available;
public:
    Book(const string& isb, const string& tit, const string& aut) {
        isbn = isb;
        title = tit;
        author = aut;
        available = 1;
    }
    Book(){}


    string getISBN() const { return isbn; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isAvailable() const { return available; }

    void reserve() { available = false; }
    void returnBook() { available = true; }
};

class Patron {
    string id;
    string name;
    Book* reservedBook = nullptr;
public:
    Patron(){}
    Patron(const string& ID, const string& Name) {
        name = Name;
        id = ID;
        reservedBook = NULL;
    }


    string getID() const { return id; }
    string getName() const { return name; }
    Book* getReservedBook() { return reservedBook; }

    void reserveBook(Book* book) {
        if (book->isAvailable() && reservedBook == nullptr) {
            reservedBook = book;
            reservedBook->reserve();
        }
    }

    void returnReservedBook() {
        if (reservedBook) {
            reservedBook->returnBook();
            reservedBook = nullptr;
        }
    }
};

class Library {

    Queue<Book> books;
    Queue<Patron> patrons;


    Patron* findPatron(const string& id) {
        Queue<Patron> tempq = patrons;
        while (!tempq.isEmpty()) {
            Patron patron = tempq.peek();
            if (patron.getID() == id) {
                return &patron;
            }
            tempq.dequeue();
        }
        return nullptr;
    }

    Book* findBook(const string& isbn) {
        Queue<Book> tempq = books;
        while (!tempq.isEmpty()) {
            Book book = tempq.peek();
            if (book.getISBN() == isbn) {
                return &book;//extracting and checking one by one
            }
            tempq.dequeue();
        }
        return nullptr;
    }


public:
    void addBook(const string& isbn, const string& title, const string& author) {
        books.enqueue(Book(isbn, title, author));//adding the book
    }

    void addPatron(const string& id, const string& name) {
        patrons.enqueue(Patron(id, name));//adding patron
    }

    void reserveBook(const string& patronID, const string& bookISBN) {
        Patron* patron = findPatron(patronID);
        Book* book = findBook(bookISBN);
        if (patron && book) {
            patron->reserveBook(book);
        }
    }

    void returnBook(const string& patronID) {
        Patron* patron = findPatron(patronID);
        if (patron) {
            patron->returnReservedBook();
        }
    }

    void displayBooks() {
        Queue<Book> tempq = books;
        while (!tempq.isEmpty()) {
            Book book = tempq.peek();
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor();
            if (book.isAvailable()) {
                cout << " Available" << endl;
            }
            else {
                cout << " Reserved" << endl;
            }
            tempq.dequeue();
        }
    }

};

int main() {
    Library lib;
    lib.addBook("123456", "Sample Book 1", "Author A");
    lib.addBook("789012", "Sample Book 2", "Author B");
    lib.addPatron("P001", "John Doe");
    lib.addPatron("P002", "Jane Smith");

    lib.reserveBook("P001", "123456");
    lib.reserveBook("P002", "789012");

    lib.displayBooks();

    return 0;
}
