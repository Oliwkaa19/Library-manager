#include <iostream>
#include "LibraryManager.h"

using namespace std;

bool Library::login_librarian()
{
    ifstream file;
    file.open("Librarians.txt",ios::in);
    if(file.good()==true)
    {
        string login_line;
        string password_line;
        string login;
        string password;
        cout << "Login: ";
        cin >> login;
        cout << endl << "Password: ";
        cin >> password;
        getline(file,login_line);
        getline(file,login_line);
        while(getline(file,login_line))
        {
            if(login==login_line)
            {
                getline(file,password_line);
                if(password==password_line)
                {
                    cout << endl <<"Log-in succesful"<<endl;
                    return true;
                    break;
                }
            }
        }
        file.close();
        return false;
    }
    else{throw "Unable to open file";}
}

void Library::save_member_to_file(Member* temp_member)
{
    ofstream file("Members.txt", ios::app);
    if(file.is_open())
    {
        file << temp_member->member_name << endl << temp_member->member_surname << endl;
        cout << "Member saved" << endl;
        file.close();
    }
    else{throw "Unable to open file";}
}
void Library::save_book_to_file(Book* temp_book)
{
    ofstream file("Books.txt", ios::app);
    if(file.is_open())
    {
        file << temp_book-> title << endl << temp_book-> genre << endl;
        cout << "Book saved" << endl;
        file.close();
    }
    else{throw "Unable to open file";}
}

int Library::count_librarians()
{
    ifstream file;
    file.open("Librarians.txt",ios::in);
    if(file.good()==true)
    {
        int librarian_count;
        int line_count = 0;
        string line;
        while(getline(file,line))
        {
            line_count++;
        }
        librarian_count = line_count/4;
        number_of_librarians = librarian_count;
        return number_of_librarians;
    }
    else{throw "Unable to open file";}
}

void Library::show_menu()
{
    cout<< endl << "LIBRARY MENU\nWho are you?" << endl;
    cout << "1 - Member" << endl << "2 - Librarian" << endl;
    int choice;
    cin >> choice;
    switch(choice)
    {
    case 1:
        Library::show_member_menu();
        break;
    case 2:
        Library::show_librarian_menu();
        break;
    default:
        throw "No such option";
    }
}

void Library::show_librarian_menu()
{
    if(Library::login_librarian())
    {
        cout << endl << "OPTIONS:";
        cout << endl << "1 - ADD A MEMBER\n2 - REMOVE A MEMBER\n3 - CHECK MEMBERSHIP TIME\n";
        cout << endl << "4 - LET BORROW A BOOK\n5 -CHECK BORROW DUE TIME\n";
    }
}

void Library::show_member_menu()
{
    if(Library::login_member())
    {
        cout << endl << "OPTIONS:";
        cout << endl << "1 - BORROW A BOOK";
        cout << endl << "2 - RETURN A BOOK";
        cout << endl << "3 - CANCEL YOUR MEMBERSHIP";
        int choice;
        cin >> choice;

        Member member;
    try{
        switch(choice)
        {
        case 1:
            member.borrow_book();
            break;
        case 2:
            member.return_book();
            break;
        case 3:
            member.cancel_membership();
            break;
        default:
            throw invalid_argument("No such option");
            break;
        }
        }
    catch(const exception& e){cerr << "Error" << e.what() << endl;}
    }
}

bool Library::login_member()
{
    string _name;
    string _surname;
    cout << "Whats your name and surname?" << endl;
    cout << "Name: ";
    cin >> _name;
    cout << endl << "Surname: ";
    cin >> _surname;

    ifstream file;
    file.open("Members.txt",ios::in);
    if(file.good()==true)
    {
        string name_line;
        string surname_line;
        cout << "Name: ";
        cin >> name;
        cout << endl << "Surname: ";
        cin >> surname;
        while(getline(_name,name_line))
        {
            if(_name==name_line)
            {
                getline(file,_surname_line);
                if(_surname==surname_line)
                {
                    return true;
                    break;
                }
            }
        }
        file.close();
        return false;
    }
    else{throw "Unable to open file";}
}

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
    //Date::set_date();
}

void Date::set_date()
{
    int _day;
    int _month;
    int _year;
    cout << "Day: ";
    cin >> _day;
    if(cin.fail()){throw "Invalid date";}
    cout << endl << "Month: ";
    cin >> _month;
    if(cin.fail()){throw "Invalid date";}
    cout << endl << "Year: ";
    cin >> _year;
    if(cin.fail()){throw "Invalid date";}
    if(_day<1 || _day>31 || _month<1 || _month>12 || _year<1910 || _year>2024 )
    {
        throw "Invalid date";
    }
    else
    {
        day = _day;
        month = _month;
        year = _year;
    }
}
