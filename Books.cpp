#include <iostream>
#include "LibraryManager.h"

using namespace std;

Book::Book()
{

}

void Book::set_book(string _title, string _genre)
{
    title = _title;
    genre = _genre;
}

Book::~Book()
{
    cout << title << " has been removed from the library.";
}
