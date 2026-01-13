#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main() 
{
    int maxBooks;
    cout << "Enter maximum number of books the library can store: ";
    cin >> maxBooks;

    if (maxBooks <= 0) 
    {
        cout << "Invalid size."<<endl;
        
        getch();
    }
    int    ids[maxBooks];
    string titles[maxBooks];
    string authors[maxBooks];
    int    issued[maxBooks];
    int bookCount = 0;
    int choice;

    do {
        cout << "\n===== Library Management System ====="<<endl;
        cout << "1. Add new book"<<endl;
        cout << "2. Show all books"<<endl;
        cout << "3. Search book by ID"<<endl;
        cout << "4. Issue a book"<<endl;
        cout << "5. Return a book"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            cout << endl;
            if (bookCount >= maxBooks) 
            {
                cout << "Library is full, cannot add more books."<<endl;
                continue;
            }

            cout << "Enter book ID (Greater than 0): ";
            cin >> ids[bookCount];
            cin.ignore();

            cout << "Enter book title: ";
            getline(cin, titles[bookCount]);

            cout << "Enter author name: ";
            getline(cin, authors[bookCount]);

            issued[bookCount] = 0;
            bookCount++;

            cout << "Book added successfully."<<endl;
            cout << "Press Enter to Continue..."<<endl;
            getch();
        }
        else if (choice == 2) 
        {
            cout << endl;
            if (bookCount == 0) 
            {
                cout << "No books in the library."<<endl;
            } 
            else 
            {
                cout << "--- All Books ---"<<endl;
                for (int i = 0; i < bookCount; i++)
                {
                    cout << "ID: " << ids[i]
                         << " | Title: " << titles[i]
                         << " | Author: " << authors[i]
                         << " | Status: " << (issued[i] ? "Issued" : "Available")
                         << endl;
                }
            }
            cout << "Press Enter to Continue..."<<endl;
            getch();
        }
        else if (choice == 3) 
        {
            cout << endl;
            int searchId;
            cout << "Enter book ID to search: ";
            cin >> searchId;

            bool found = false;
            for (int i = 0; i < bookCount; i++) 
            {
                if (ids[i] == searchId) 
                {
                    cout << "Book found:\n";
                    cout << "ID: " << ids[i]
                         << " | Title: " << titles[i]
                         << " | Author: " << authors[i]
                         << " | Status: " << (issued[i] ? "Issued" : "Available")
                         << endl;
                    found = true;
                    break;
                }
            }
            if (!found) 
            {
                cout << "Book with ID " << searchId << " not found."<<endl;
            }
            cout << "Press Enter to Continue..."<<endl;
            getch();
        }
        else if (choice == 4) 
        {
            cout << endl;
            int issueId;
            cout << "Enter book ID to issue: ";
            cin >> issueId;

            bool found = false;
            for (int i = 0; i < bookCount; i++) 
            {
                if (ids[i] == issueId) 
                {
                    found = true;
                    if (issued[i] == 1) 
                    {
                        cout << "Book is already issued."<<endl;
                    } 
                    else 
                    {
                        issued[i] = 1;
                        cout << "Book issued successfully."<<endl;
                    }
                    break;
                }
            }
            if (!found) 
            {
                cout << "Book with that ID not found."<<endl;
            }
            cout << "Press Enter to Continue..."<<endl;
            getch();
        }
        else if (choice == 5) 
        {
            cout << endl;
            int returnId;
            cout << "Enter book ID to return: ";
            cin >> returnId;

            bool found = false;
            for (int i = 0; i < bookCount; i++) 
            {
                if (ids[i] == returnId) 
                {
                    found = true;
                    if (issued[i] == 0) 
                    {
                        cout << "This book was not issued."<<endl;
                    } 
                    else 
                    {
                        issued[i] = 0;
                        cout << "Book returned successfully."<<endl;
                    }
                    break;
                }
            }
            if (!found) 
            {
                cout << "Book with that ID not found."<<endl;
            }
            cout << "Press Enter to Continue..."<<endl;
            getch();
        }
        else if (choice == 6) 
        {
            cout << endl;
            cout << "Exiting..."<<endl;
            getch();
        }
        else 
        {
            cout << "Invalid choice. Try again."<<endl;
        }

    } 
    while (choice != 6);
    return 0;
}