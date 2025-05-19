#include "UIHelper.h"


namespace LaibraryProject {
	//Print and export
	void UIHelper::PrintTable(DataGridView^ table)
	{
		if (table == nullptr || table->RowCount == 0) {
			MessageBox::Show("No data to export.");
			return;
		}

		SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
		saveDialog->Filter = "PDF Files|*.pdf";
		saveDialog->Title = "Save Table as PDF";
		saveDialog->FileName = "table_output.pdf";

		if (saveDialog->ShowDialog() != DialogResult::OK)
			return;

		String^ filePath = saveDialog->FileName;
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(filePath, false, System::Text::Encoding::ASCII);

		// PDF Header
		writer->WriteLine("%PDF-1.4");
		writer->WriteLine("1 0 obj << /Type /Catalog /Pages 2 0 R >> endobj");
		writer->WriteLine("2 0 obj << /Type /Pages /Kids [3 0 R] /Count 1 >> endobj");

		// Build the content stream
		System::Text::StringBuilder^ content = gcnew System::Text::StringBuilder();
		content->Append("BT\n/F1 10 Tf\n");

		int startX = 50;
		int startY = 750;
		int cellSpacingX = 100;
		int rowSpacingY = 20;
		int y = startY;

		// Write headers
		for (int col = 0; col < table->ColumnCount; col++) {
			String^ header = table->Columns[col]->HeaderText;
			header = header->Replace("(", "\\(")->Replace(")", "\\)");
			int x = startX + (col * cellSpacingX);
			content->AppendFormat("1 0 0 1 {0} {1} Tm ({2}) Tj\n", x, y, header);
		}
		y -= rowSpacingY;

		// Write each row
		for (int row = 0; row < table->RowCount; row++) {
			if (table->Rows[row]->IsNewRow) continue;

			for (int col = 0; col < table->ColumnCount; col++) {
				String^ val = table->Rows[row]->Cells[col]->Value != nullptr ?
					table->Rows[row]->Cells[col]->Value->ToString() : "";
				val = val->Replace("(", "\\(")->Replace(")", "\\)");

				int x = startX + (col * cellSpacingX);
				content->AppendFormat("1 0 0 1 {0} {1} Tm ({2}) Tj\n", x, y, val);
			}
			y -= rowSpacingY;
		}
		content->Append("ET\n");

		// Write objects
		writer->WriteLine("3 0 obj << /Type /Page /Parent 2 0 R /MediaBox [0 0 612 792] /Contents 4 0 R /Resources << /Font << /F1 5 0 R >> >> >> endobj");
		writer->WriteLine("4 0 obj << /Length {0} >> stream", content->Length);
		writer->Write(content->ToString());
		writer->WriteLine("endstream endobj");
		writer->WriteLine("5 0 obj << /Type /Font /Subtype /Type1 /BaseFont /Helvetica >> endobj");

		// xref & trailer
		writer->WriteLine("xref");
		writer->WriteLine("0 6");
		writer->WriteLine("0000000000 65535 f ");
		writer->WriteLine("0000000010 00000 n ");
		writer->WriteLine("0000000067 00000 n ");
		writer->WriteLine("0000000116 00000 n ");
		writer->WriteLine("0000000216 00000 n ");
		writer->WriteLine("0000000410 00000 n ");
		writer->WriteLine("trailer << /Size 6 /Root 1 0 R >>");
		writer->WriteLine("startxref");
		writer->WriteLine("500");
		writer->WriteLine("%%EOF");

		writer->Close();

		MessageBox::Show("PDF saved:\n" + filePath);
	}
	void UIHelper::ExportTableToCsv(DataGridView^ table)
	{
		if (table == nullptr || table->RowCount == 0) {
			MessageBox::Show("No data to export.");
			return;
		}

		SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
		saveDialog->Filter = "CSV Files|*.csv";
		saveDialog->Title = "Save Table as CSV";
		saveDialog->FileName = "table_export.csv";

		if (saveDialog->ShowDialog() != DialogResult::OK)
			return;

		String^ filePath = saveDialog->FileName;

		try
		{
			System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(filePath, false, System::Text::Encoding::UTF8);

			// Write headers
			for (int col = 0; col < table->ColumnCount; col++) {
				String^ header = table->Columns[col]->HeaderText;
				writer->Write("\"" + header->Replace("\"", "\"\"") + "\"");
				if (col < table->ColumnCount - 1)
					writer->Write(",");
			}
			writer->WriteLine();

			// Write rows
			for (int row = 0; row < table->RowCount; row++) {
				if (table->Rows[row]->IsNewRow) continue;

				for (int col = 0; col < table->ColumnCount; col++) {
					String^ cell = table->Rows[row]->Cells[col]->Value != nullptr ?
						table->Rows[row]->Cells[col]->Value->ToString() : "";
					cell = cell->Replace("\"", "\"\"");
					writer->Write("\"" + cell + "\"");
					if (col < table->ColumnCount - 1)
						writer->Write(",");
				}
				writer->WriteLine();
			}

			writer->Close();
			MessageBox::Show("CSV file saved:\n" + filePath);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Failed to export CSV: " + ex->Message);
		}
	}
	void UIHelper::PrintRow(DataGridViewCellMouseEventArgs^ e, DataGridView^ table)
	{
		if (e->RowIndex < 0) return;

		DataGridViewRow^ row = table->Rows[e->RowIndex];
		String^ rowData = "";

		for each (DataGridViewCell ^ cell in row->Cells)
		{
			if (cell->Value != nullptr)
			{
				rowData += cell->OwningColumn->HeaderText + ": " + cell->Value->ToString() + "\n";
			}
			else
			{
				rowData += cell->OwningColumn->HeaderText + ": NULL\n";
			}
		}

		MessageBox::Show(rowData, "Row Data");
	}

	void UIHelper::FilterDataGridView(DataGridView^ table, String^ searchText)
	{
		if (table == nullptr)
			return;

		String^ filterText = searchText == nullptr ? "" : searchText->ToLower();

		for each (DataGridViewRow ^ row in table->Rows) {
			if (row->IsNewRow) continue;

			bool rowVisible = false;

			for each (DataGridViewCell ^ cell in row->Cells) {
				if (cell->Value != nullptr) {
					String^ cellText = cell->Value->ToString()->ToLower();
					if (cellText->Contains(filterText)) {
						rowVisible = true;
						break;
					}
				}
			}

			row->Visible = rowVisible;
		}
	}




	


	void UIHelper::FillControlsFromSelectedRow(
		DataGridView^ table,
		Dictionary<String^, TextBox^>^ columnToControlMap)
	{
		if (table->SelectedRows->Count == 0) return;

		DataGridViewRow^ row = table->SelectedRows[0];
		for each (KeyValuePair<String^, TextBox^> kvp in columnToControlMap)
		{
			String^ colName = kvp.Key;
			TextBox^ ctrl = kvp.Value;

			// Fix: Check if the column exists in the DataGridView instead of using Contains  
			if (table->Columns->Contains(colName) && row->Cells[colName]->Value != nullptr)
			{
				ctrl->Text = row->Cells[colName]->Value->ToString();
			}
			else
			{
				ctrl->Text = "";
			}
		}
	}
}
