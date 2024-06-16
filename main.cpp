#include <iostream>
#include "LibraryManager.h"

using namespace std;

int main()
{
    Library l1;
    Member* m1 = nullptr;
    Book* b1 = nullptr;
    Librarian* lib1 = nullptr;

    try
    {
        m1 = new Member();
        lib1 = new Librarian();
        lib1->add_member(m1);
        l1.save_member_to_file(m1);
        l1.show_menu();
    }
    catch(const char* txtException)
    {
        cout << "Error";
    }
}
