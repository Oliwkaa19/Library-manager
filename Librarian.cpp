#include <iostream>
#include "LibraryManager.h"
using namespace std;

Librarian::Librarian()
{

}

Librarian::~Librarian()
{
    cout << "lib destroyed";
}

void Librarian::add_member(Member* temp_member)
{
    string _member_name;
    string _member_surname;
    cout << "Name: ";
    cin >> _member_name;
    cout << endl << "Surname: ";
    cin >> _member_surname;
    cout << "Age: ";
    temp_member->set_member(_member_name,_member_surname);
}

void Librarian::add_book(Book* temp_book)
{
    string _title,_genre;
    cout << "Title: ";
    cin >> _title;
    cout << endl << "Pick a genre(by number)\n1-Drama\n2-Comedy\n3-Crime\n4-Romance" << endl;
    int switch_number = 0;
    cin >> switch_number;
    switch(switch_number)
    {
    case 1:
        _genre = "Drama";
        cout << "Book added"<<endl;
        temp_book->set_book(_title,_genre);
        break;
    case 2:
        _genre = "Comedy";
        cout << "Book added"<<endl;
        temp_book->set_book(_title,_genre);
        break;
    case 3:
        _genre = "Crime";
        cout << "Book added"<<endl;
        temp_book->set_book(_title,_genre);
        break;
    case 4:
        _genre = "Romance";
        cout << "Book added"<<endl;
        temp_book->set_book(_title,_genre);
        break;
    default:
        cout << "Invalid genre";
        break;
    }

}
