#include <iostream>
#include "LibraryManager.h"

using namespace std;

int main()
{
    Library l1;
    Member* m1 = nullptr;
    Book* b1 = nullptr;
    Librarian* lib1 = nullptr;
    Date* d1;

    try
    {
        d1 = new Date();
        d1->set_date();
        m1 = new Member();
        lib1 = new Librarian();
        b1 = new Book();
        //lib1->add_member(m1);
        //l1.save_member_to_file(m1);
        l1.show_menu();
    }
    catch(const exception& e)
    {
        delete m1;
        delete lib1;
        m1 = nullptr;
        lib1 = nullptr;
        cerr << e.what() << endl;
    }
}
