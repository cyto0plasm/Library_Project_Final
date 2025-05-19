#pragma once

#include "../Models/BookSuggestionModel.h"
#include "../Database/DBConnection.h"
#include "../Models/StudentModel.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::SQLite;

namespace LaibraryProject {
    public ref class BookSuggestionController {
    public:
        BookSuggestionModel^ Create(BookSuggestionModel^ suggestion);
        BookSuggestionModel^ GetById(int id);
        List<BookSuggestionModel^>^ GetAll();
        bool Update(BookSuggestionModel^ suggestion);
        bool Delete(int id);
        List<StudentModel^>^ BookSuggestionController::SearchStudentsWithSuggestions(System::String^ searchTerm, int userId);
        List<StudentModel^>^ SearchStudents(System::String^ searchTerm, int userId);

        List<BookSuggestionModel^>^ GetByStudentId(int studentId);
        List<BookSuggestionModel^>^ GetByUserId(int userId);
    };
}