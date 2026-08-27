#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int i, string t, string a, bool status = false)
    {
        id = i;
        title = t;
        author = a;
        issued = status;
    }
};

class Member
{
public:
    int id;
    string name;

    Member(int i, string n)
    {
        id = i;
        name = n;
    }
};

vector<Book> books;
vector<Member> members;

// Save books to file
void saveBooks()
{
    ofstream file("library.txt");

    for (const Book &b : books)
    {
        file << b.id << "|"
             << b.title << "|"
             << b.author << "|"
             << b.issued << endl;
    }

    file.close();
}

// Load books from file
void loadBooks()
{
    ifstream file("library.txt");

    if (!file)
        return;

    string id, title, author, issued;

    while (getline(file, id, '|') &&
           getline(file, title, '|') &&
           getline(file, author, '|') &&
           getline(file, issued))
    {
        books.push_back(
            Book(stoi(id), title, author, stoi(issued))
        );
    }

    file.close();
}

// Add a new book
void addBook()
{
    int id;
    string title, author;

    cout << "\nEnter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));

    saveBooks();

    cout << "\nBook added successfully!\n";
}

// Display all books
void displayBooks()
{
    if (books.empty())
    {
        cout << "\nNo books available.\n";
        return;
    }

    cout << "\n========== ALL BOOKS ==========\n";

    for (const Book &b : books)
    {
        cout << "\nBook ID: " << b.id;
        cout << "\nTitle: " << b.title;
        cout << "\nAuthor: " << b.author;
        cout << "\nStatus: "
             << (b.issued ? "Issued" : "Available");
        cout << "\n-----------------------------\n";
    }
}

// Search book by title
void searchByTitle()
{
    string title;
    cin.ignore();

    cout << "\nEnter title to search: ";
    getline(cin, title);

    bool found = false;

    for (const Book &b : books)
    {
        if (b.title.find(title) != string::npos)
        {
            cout << "\nBook ID: " << b.id;
            cout << "\nTitle: " << b.title;
            cout << "\nAuthor: " << b.author;
            cout << "\nStatus: "
                 << (b.issued ? "Issued" : "Available");
            cout << "\n-----------------------------\n";

            found = true;
        }
    }

    if (!found)
        cout << "\nBook not found.\n";
}

// Search book by author
void searchByAuthor()
{
    string author;
    cin.ignore();

    cout << "\nEnter author name to search: ";
    getline(cin, author);

    bool found = false;

    for (const Book &b : books)
    {
        if (b.author.find(author) != string::npos)
        {
            cout << "\nBook ID: " << b.id;
            cout << "\nTitle: " << b.title;
            cout << "\nAuthor: " << b.author;
            cout << "\nStatus: "
                 << (b.issued ? "Issued" : "Available");
            cout << "\n-----------------------------\n";

            found = true;
        }
    }

    if (!found)
        cout << "\nBook not found.\n";
}

// Issue a book
void issueBook()
{
    int id;

    cout << "\nEnter Book ID to issue: ";
    cin >> id;

    for (Book &b : books)
    {
        if (b.id == id)
        {
            if (b.issued)
            {
                cout << "\nBook is already issued.\n";
            }
            else
            {
                b.issued = true;
                saveBooks();

                cout << "\nBook issued successfully!\n";
            }

            return;
        }
    }

    cout << "\nBook not found.\n";
}

// Return a book
void returnBook()
{
    int id;

    cout << "\nEnter Book ID to return: ";
    cin >> id;

    for (Book &b : books)
    {
        if (b.id == id)
        {
            if (!b.issued)
            {
                cout << "\nBook is already available.\n";
            }
            else
            {
                b.issued = false;
                saveBooks();

                cout << "\nBook returned successfully!\n";
            }

            return;
        }
    }

    cout << "\nBook not found.\n";
}

// Add member
void addMember()
{
    int id;
    string name;

    cout << "\nEnter Member ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Member Name: ";
    getline(cin, name);

    members.push_back(Member(id, name));

    cout << "\nMember added successfully!\n";
}

// Display members
void displayMembers()
{
    if (members.empty())
    {
        cout << "\nNo members registered.\n";
        return;
    }

    cout << "\n========== MEMBERS ==========\n";

    for (const Member &m : members)
    {
        cout << "\nMember ID: " << m.id;
        cout << "\nName: " << m.name;
        cout << "\n-----------------------------\n";
    }
}

int main()
{
    loadBooks();

    int choice;

    do
    {
        cout << "\n\n================================";
        cout << "\n   LIBRARY MANAGEMENT SYSTEM";
        cout << "\n================================";

        cout << "\n1. Add Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Search Book by Title";
        cout << "\n4. Search Book by Author";
        cout << "\n5. Issue Book";
        cout << "\n6. Return Book";
        cout << "\n7. Add Member";
        cout << "\n8. Display Members";
        cout << "\n9. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchByTitle();
            break;

        case 4:
            searchByAuthor();
            break;

        case 5:
            issueBook();
            break;

        case 6:
            returnBook();
            break;

        case 7:
            addMember();
            break;

        case 8:
            displayMembers();
            break;

        case 9:
            cout << "\nThank you for using Library Management System!\n";
            break;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}