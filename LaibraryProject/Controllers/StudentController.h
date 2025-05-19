#pragma once

#include "../Models/StudentModel.h"
using namespace System;
using namespace System::Collections::Generic;

namespace LaibraryProject {
    public ref class StudentsController {
    public:
        //Relations
        static List<StudentModel^>^ GetByUserId(int userId);
        //Normal cruds
        static StudentModel^ Create(StudentModel^ student);
        static StudentModel^ GetById(int id);
        static List<StudentModel^>^ GetAll();
        static bool Update(StudentModel^ student);
        static bool Delete(int id);
    };
}
