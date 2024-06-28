//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//
//class Book {
//public:
//    Book(const std::string& isbn, const std::string& title, const std::string& author)
//        : isbn(isbn), title(title), author(author), available(true) {}
//
//    std::string getISBN() const { return isbn; }
//    std::string getTitle() const { return title; }
//    std::string getAuthor() const { return author; }
//    bool isAvailable() const { return available; }
//
//    void reserve() { available = false; }
//    void returnBook() { available = true; }
//
//private:
//    std::string isbn;
//    std::string title;
//    std::string author;
//    bool available;
//};
//
//class Patron {
//public:
//    Patron(const std::string& id, const std::string& name)
//        : id(id), name(name) {}
//
//    std::string getID() const { return id; }
//    std::string getName() const { return name; }
//    Book* getReservedBook() { return reservedBook; }
//
//    void reserveBook(Book* book) {
//        if (book->isAvailable() && reservedBook == nullptr) {
//            reservedBook = book;
//            reservedBook->reserve();
//        }
//    }
//
//    void returnReservedBook() {
//        if (reservedBook) {
//            reservedBook->returnBook();
//            reservedBook = nullptr;
//        }
//    }
//
//private:
//    std::string id;
//    std::string name;
//    Book* reservedBook = nullptr;
//};
//
//class Library {
//public:
//    void addBook(const std::string& isbn, const std::string& title, const std::string& author) {
//        books.push_back(Book(isbn, title, author));
//    }
//
//    void addPatron(const std::string& id, const std::string& name) {
//        patrons.push_back(Patron(id, name));
//    }
//
//    void reserveBook(const std::string& patronID, const std::string& bookISBN) {
//        Patron* patron = findPatron(patronID);
//        Book* book = findBook(bookISBN);
//        if (patron && book) {
//            patron->reserveBook(book);
//        }
//    }
//
//    void returnBook(const std::string& patronID) {
//        Patron* patron = findPatron(patronID);
//        if (patron) {
//            patron->returnReservedBook();
//        }
//    }
//
//    void displayBooks() {
//        for (const Book& book : books) {
//            std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor();
//            if (book.isAvailable()) {
//                std::cout << " (Available)" << std::endl;
//            }
//            else {
//                std::cout << " (Reserved)" << std::endl;
//            }
//        }
//    }
//
//private:
//    std::vector<Book> books;
//    std::vector<Patron> patrons;
//
//    Patron* findPatron(const std::string& id) {
//        for (Patron& patron : patrons) {
//            if (patron.getID() == id) {
//                return &patron;
//            }
//        }
//        return nullptr;
//    }
//
//    Book* findBook(const std::string& isbn) {
//        for (Book& book : books) {
//            if (book.getISBN() == isbn) {
//                return &book;
//            }
//        }
//        return nullptr;
//    }
//};
//
//int main() {
//    Library library;
//    library.addBook("123456", "Sample Book 1", "Author A");
//    library.addBook("789012", "Sample Book 2", "Author B");
//    library.addPatron("P001", "John Doe");
//    library.addPatron("P002", "Jane Smith");
//
//    library.reserveBook("P001", "123456");
//    library.reserveBook("P002", "789012");
//
//    library.displayBooks();
//
//    return 0;
//}
