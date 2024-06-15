#include <iostream>
#include "LibraryManager.h"

using namespace std;

Member::Member()
{
    books = 0;
}

void Member::set_member()
{
    string _member_name;
    string _member_surname;
    int _age;
    cout << "Name: ";
    cin >> _member_name;
    cout << endl << "Surname: ";
    cin >> _member_surname;
    cout << "Age: ";
    cin >> _age;
    member_name = _member_name;
    member_surname = _member_surname;
    if(cin.fail())
    {
        cin.clear();
        cout << "Error in creating a member" << endl;
        throw "Invalid age";
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
