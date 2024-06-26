#include <iostream>
#include "LibraryManager.h"

using namespace std;

Member::Member()
{
    books = 0;
}

void Member::set_member(string _member_name,string _member_surname)
{
    int _age;
    cin >> _age;
    if(cin.fail() || _age<16 || age>120)
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid age, can't register in library";
    }
    else
    {
        member_name = _member_name;
        member_surname = _member_surname;
        age = _age;
    }
}

void Member::borrow_book()
{
    cout << "Borrowed";
}

void Member::return_book()
{
    cout << "Returned";
}

void Member::cancel_membership()
{
    cout << "Canceled";
}
Member::~Member()
{
    cout << "Member destroyed";
}
