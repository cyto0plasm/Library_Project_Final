#pragma once
using namespace System;

namespace LaibraryProject {
    public ref class BookModel {
    public:
        property int Id;
        property int UserId;  // required foreign key

        property String^ Name;
        property String^ Author;
        property String^ Description;

        // Optional foreign key
        Nullable<int> LoanId;
    };
}
