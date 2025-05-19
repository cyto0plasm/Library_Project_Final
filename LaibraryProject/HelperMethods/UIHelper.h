#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

namespace LaibraryProject {

    public ref class UIHelper abstract sealed // static class
    {
    public:
        static void FillControlsFromSelectedRow(
            DataGridView^ table,
            Dictionary<String^, TextBox^>^ columnToControlMap);
        static void PrintTable(DataGridView^ table);
        static void UIHelper::ExportTableToCsv(DataGridView^ table);
        static void PrintRow(DataGridViewCellMouseEventArgs^ e, DataGridView^ table);
        static void FilterDataGridView(DataGridView^ table, String^ searchText);
    };
}
