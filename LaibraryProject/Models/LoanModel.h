#pragma once
#include <cliext/vector>

using namespace System;
using namespace System::Data;
namespace LaibraryProject {
    public ref class LoanModel {
    public:
        // Properties
        property int Id;
        property System::Nullable<int> UserId;
        property int StudentId;
        property int BookId;
        property System::DateTime LoanDate;
        property System::DateTime ReturnDate;
        property System::String^ Status;
        property System::DateTime CreatedAt;
        property System::DateTime UpdatedAt;

        // Constructor
        LoanModel() {
            CreatedAt = System::DateTime::Now;
            UpdatedAt = System::DateTime::Now;
            Status = "active"; // Default status
        }

        // Methods
        static property array<System::String^>^ ValidStatuses {
            array<System::String^>^ get() {
                return gcnew array<System::String^> { "active", "returned", "overdue", "lost" };
            }
        }

        bool IsActive() {
            return Status->Equals("active");
        }

        bool IsOverdue() {
            return Status->Equals("overdue") ||
                (Status->Equals("active") && ReturnDate < System::DateTime::Now);
        }

        void MarkAsReturned() {
            Status = "returned";
            UpdatedAt = System::DateTime::Now;
        }

        void MarkAsOverdue() {
            Status = "overdue";
            UpdatedAt = System::DateTime::Now;
        }
    };
}