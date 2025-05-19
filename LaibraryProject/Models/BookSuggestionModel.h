#pragma once

using namespace System;
using namespace System::Data;
namespace LaibraryProject {
    public ref class BookSuggestionModel {
    public:
        property int Id;
        property Nullable<int> UserId;
        property int StudentId;
        property System::String^ Suggestion;
        property System::DateTime CreatedAt;
        property System::DateTime UpdatedAt;
    };
}