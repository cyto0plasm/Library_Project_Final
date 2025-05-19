#pragma once
using namespace System;

namespace LaibraryProject {
    public ref class UserModel {
    public:
        property int Id;
        property String^ Name;
        property String^ Password;
        property DateTime Created_At;
        property DateTime Updated_At;
    };
}
