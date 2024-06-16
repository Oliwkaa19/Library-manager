#include <iostream>
#include <fstream>
#include <limits>
using namespace std;


class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();
    void set_date();
    void get_date();
    void show_date();
    void edit_date();
    friend class Member;
    friend class Library;
    friend class Librarian;

};

class Member
{
public:
    string member_name;
    string member_surname;
    int age;
    int books;
    Date membership_start;
    Date membership_time;
public:
    Member();
    ~Member();
    void set_member(string _member_name,string _member_surname_,int _age);
    void get_member();
    void borrow_book();
    void return_book();
    void cancel_membership();
    friend class Library;
};

class Book
{
private:
    string title;
    string genre;
public:
    Book();
    ~Book();
    void set_book();
    void get_book();
    friend class Library;
};

class Librarian
{
private:
    string lib_name;
    string lib_surname;

public:
    Librarian();
    ~Librarian();
    void add_member(Member* temp_member);
    void remove_member(Member* temp_member);
    void check_membership_time(Member* temp_member);
    void check_due_time(Member* temp_member);
    void allow_book_borrow(Member* temp_member);
    friend class Library;
};

class Library
{
private:
    int number_of_members;
    int number_of_librarians;
    int shelf_number;
    int amount_in_stock;
public:
    void add_book();
    void remove_book();
    void register_librarian();
    void unregister_librarian();
    void charge_member();
    void borrow_time_counter();
    void show_member_list();
    void save_member_to_file(Member* temp_member);
    void save_book_to_file(Book* temp_book);
    void show_menu();
    void show_member_menu();
    void show_librarian_menu();

    bool login_member();
    bool login_librarian();
    int count_librarians();
    int count_members();
    friend class Librarian;
};
