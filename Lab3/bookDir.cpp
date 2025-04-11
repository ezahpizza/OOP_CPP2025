#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
    string title;
    string author;
    string publisher;
    float price;

public:
    Book(string t, string a, string p, float pr)
        : title(t), author(a), publisher(p), price(pr) {}

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: $" << price << endl;
    }

    bool matches(const string &t, const string &a) const {
        return (title == t && author == a);
    }
};

int main() {
    cout << "== Book Inventory ==" << endl;

    vector<Book> inventory = {
        Book("C++ Primer", "Lippman", "Pearson", 45.5),
        Book("Let Us C", "Yashwant Kanetkar", "BPB", 30.0),
        Book("Clean Code", "Robert C. Martin", "Prentice Hall", 50.0)
    };

    string searchTitle, searchAuthor;
    cout << "Enter title: ";
    getline(cin, searchTitle);
    cout << "Enter author: ";
    getline(cin, searchAuthor);

    bool found = false;
    for (const auto &book : inventory) {
        if (book.matches(searchTitle, searchAuthor)) {
            cout << "Book found!\n";
            book.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not available in inventory." << endl;
    }

    cout << "=====================\n";
    
    return 0;
}