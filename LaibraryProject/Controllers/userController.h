#pragma once

#include "../Database/DBConnection.h"
#include "../Models/UserModel.h"

using namespace System;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace LaibraryProject {

    public ref class UsersController {
    public:
         UserModel^ Register(String^ name, String^ password);
         UserModel^ Login(String^ name, String^ password);
         UserModel^ Create(UserModel^ user);
         UserModel^ GetById(int id);
         List<UserModel^>^ GetAll();
         bool Update(UserModel^ user);
         bool Delete(int id);
    };
}
