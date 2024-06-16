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
    int _age;
    cout << "Name: ";
    cin >> _member_name;
    cout << endl << "Surname: ";
    cin >> _member_surname;
    cout << "Age: ";
    temp_member->set_member(_member_name,_member_surname, _age);
}

