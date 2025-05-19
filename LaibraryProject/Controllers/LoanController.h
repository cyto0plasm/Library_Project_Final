#include "../Models/LoanModel.h"
#include "../Models/Book.h"
#include "../Models/StudentModel.h"
#include "../Database/DBConnection.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::SQLite;

namespace LaibraryProject {
	public ref class LoanController {
	public:
		LoanModel^ Create(LoanModel^ loan);


		LoanModel^ GetById(int id);
		List<LoanModel^>^ GetAll();
		List<LoanModel^>^ GetByStudentId(int studentId);
		List<LoanModel^>^ GetByBookId(int bookId);
		bool Update(LoanModel^ loan);
		bool Delete(int id);
		List<LoanModel^>^ GetActiveLoans();
		List<StudentModel^>^ SearchStudents(System::String^ searchTerm, int userId)
			;
		List<BookModel^>^ SearchBooks(System::String^ searchTerm);
	};

};