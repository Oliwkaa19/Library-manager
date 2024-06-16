#include <iostream>
#include "LibraryManager.h"

using namespace std;


void Book::set_book()
{
    string _title;
    cout << "Title: ";
    cin >> _title;
    cout << endl << "Pick a genre(by number)\n1-Drama\n2-Comedy\n3-Crime\n4-Romance" << endl;
    int switch_number = 0;
    cin >> switch_number;
    switch(switch_number)
    {
    case 1:
        genre = "Drama";
        title = _title;
        cout << "Book added"<<endl;
        break;
    case 2:
        genre = "Comedy";
        title = _title;
        cout << "Book added"<<endl;
        break;
    case 3:
        genre = "Crime";
        title = _title;
        cout << "Book added"<<endl;
        break;
    case 4:
        genre = "Romance";
        title = _title;
        cout << "Book added"<<endl;
        break;
    default:
        cout << "Invalid genre";
        throw "Invalid genre";
        break;
    }
}

Book::~Book()
{
    cout << title << " has been removed from the library.";
}
