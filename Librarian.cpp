#include <iostream>
#include "LibraryManager.h"
using namespace std;

Librarian::Librarian()
{
    lib_name = " ";
    lib_surname = " ";
}

Librarian::~Librarian()
{
    cout << "lib destroyed";
}
