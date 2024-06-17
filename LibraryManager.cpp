#include <iostream>
#include "LibraryManager.h"

using namespace std;

void Library::save_member_to_file(Member* temp_member)
{
    ofstream file("Members.txt", ios::app);
    if(file.is_open())
    {
        file << temp_member->member_name << endl << temp_member->member_surname << endl;
        cout << "Member saved" << endl;
        file.close();
    }
    else{throw ios_base::failure("Unable to open file");}
}

void Library::save_book_to_file(Book* temp_book)
{
    try{
        ofstream file("Books.txt", ios::app);
        if(file.is_open())
        {
            file << temp_book-> title << endl << temp_book-> genre << endl;
            cout << "Book saved" << endl;
            file.close();
        }
        else{throw ios_base::failure("Unable to open file");}
        }
    catch(const exception& e){cerr << "Error" << e.what() << endl;}
}

int Library::count_librarians()
{
    try
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
        else{throw ios_base::failure("Unable to open file");}
    }
    catch(const exception& e){cerr << e.what() << endl;}
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
        cout << "No such option";
        break;
    }
}

void Library::show_librarian_menu()
{
    if(Library::login_librarian())
    {
        cout << endl << "OPTIONS:";
        cout << endl << "1 - ADD A MEMBER\n2 - REMOVE A MEMBER\n3 - CHECK MEMBERSHIP TIME";
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
            cout<<"No such option";
            break;
        }
    }
    else
    {
        cout<<"Could not find your profile";
    }
}

bool Library::login_librarian()
{
    try{
        ifstream file;
        file.open("Librarians.txt",ios::in);
        if(file.good()==true)
        {
            string login_line, password_line;
            string login, password;
            cout << "Login: ";
            cin >> login;
            cout << endl << "Password: ";
            cin >> password;

            while(getline(file,login_line))      //1k
            {
                getline(file,login_line);        //2k
                getline(file,login_line);        //3k
                if(login==login_line)
                {
                    getline(file,password_line); //4k
                    if(password==password_line)
                    {
                        cout << endl <<"Log-in succesful"<<endl;
                        file.close();
                        return true;
                    }
                }
            }
            file.close();
            return false;
    }
    else{throw ios_base::failure("Unable to open file");}
    }
    catch(const exception& e){}
}

bool Library::login_member()
{
    string _name,_surname;
    cout << "Whats your name and surname?" << endl;
    cout << "Name: ";
    cin >> _name;
    cout << endl << "Surname: ";
    cin >> _surname;
    try{
    ifstream file;
    file.open("Members.txt",ios::in);
    if(file.good()==true)
    {
        string name_line;
        string surname_line;
        while(getline(file,name_line))
        {
            if(_name==name_line)
            {
                getline(file,surname_line);
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
    else{throw ios_base::failure("Unable to open file");}
    }
   catch(const exception& e){}
}

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

void Date::set_date()
{
    int _day;
    int _month;
    int _year;

    cin >> _day;
    if(cin.fail() || _day<0 || _day>31)
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid Date";
    }
    else{
        cin >> _month;
        if(cin.fail() || _month<0 || _month>12)
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid Date";
        }
        else
        {
            cin >> _year;
            if(cin.fail() || _year<1910 || _year>2024)
            {
                cin.clear();
                cin.ignore();
                cout << "Invalid Date";
            }
            else
            {
                day = _day;
                month = _month;
                year = _year;
            }
        }
    }
}
