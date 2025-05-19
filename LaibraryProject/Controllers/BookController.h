#pragma once
#include "../Models/Book.h"
#include "../Database/DBConnection.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::SQLite;

namespace LaibraryProject {

    public ref class BooksController {
    public:
        //crud -create reed update delete operations
        BookModel^ Create(BookModel^ book);
        BookModel^ GetById(int id);
        List<BookModel^>^ GetAll();
        List<BookModel^>^ GetByUserId(int userId);
        bool Update(BookModel^ book);
        bool Delete(int id);
    };
}
