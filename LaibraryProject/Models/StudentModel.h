#pragma once
using namespace System;

namespace LaibraryProject {
    public ref class StudentModel {
    public:
        property int Id;
        property String^ Name;
        property int SeatNumber;
        property String^ Department;
        property String^ Email;

        // Optional foreign keys
        Nullable<int> UserId;
        Nullable<int> SuggestsId;
        Nullable<int> LoanId;

        property DateTime Created_At;
        property DateTime Updated_At;
    };
}
