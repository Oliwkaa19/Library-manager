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
        lib1 = new Librarian();
        m1 = new Member();
        b1 = new Book();
    }
    catch(const char* txtException)
    {
        delete m1;
        m1 = nullptr;
        delete b1;
        b1 = nullptr;
        delete lib1;
        lib1 = nullptr;
    }
    try
    {
        l1.show_menu();
    }
    catch(const char* txtException)
    {
        cout << "error";
    }
}
