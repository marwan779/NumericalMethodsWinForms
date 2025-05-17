#pragma once
#include <string>
#include "PolynomialFitter.h"
#include <msclr/marshal_cppstd.h>
#include<vector>
#include "Helper.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CurveFittingForm
	/// </summary>
	public ref class CurveFittingForm : public System::Windows::Forms::Form
	{
	public:
		CurveFittingForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			dataGridView1->ColumnCount = 2;
			dataGridView1->Rows->Clear();
			dataGridView1->Columns[0]->Name = "X";
			dataGridView1->Columns[1]->Name = "Y";
			dataGridView1->Rows->Add(nullptr, nullptr);


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CurveFittingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ txtDeg;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ Calc;
	private: System::Windows::Forms::Button^ clear;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtDeg = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->Calc = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(58, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Degree";
			// 
			// txtDeg
			// 
			this->txtDeg->Location = System::Drawing::Point(149, 68);
			this->txtDeg->Name = L"txtDeg";
			this->txtDeg->Size = System::Drawing::Size(100, 24);
			this->txtDeg->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(61, 106);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 26;
			this->dataGridView1->Size = System::Drawing::Size(403, 476);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CurveFittingForm::dataGridView1_CellContentClick);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(678, 64);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(460, 571);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"";
			// 
			// Calc
			// 
			this->Calc->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Calc->Location = System::Drawing::Point(377, 624);
			this->Calc->Name = L"Calc";
			this->Calc->Size = System::Drawing::Size(204, 83);
			this->Calc->TabIndex = 4;
			this->Calc->Text = L"Calc";
			this->Calc->UseVisualStyleBackColor = true;
			this->Calc->Click += gcnew System::EventHandler(this, &CurveFittingForm::button1_Click);
			// 
			// clear
			// 
			this->clear->Location = System::Drawing::Point(61, 588);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(124, 47);
			this->clear->TabIndex = 5;
			this->clear->Text = L"Clear";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &CurveFittingForm::clear_Click);
			// 
			// CurveFittingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1150, 759);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->Calc);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->txtDeg);
			this->Controls->Add(this->label1);
			this->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Name = L"CurveFittingForm";
			this->Text = L"Curve Fitting Method";
			this->Load += gcnew System::EventHandler(this, &CurveFittingForm::CurveFittingForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			int degree = 0;
			// Get the degree from the TextBox
			 if (String::IsNullOrWhiteSpace(txtDeg->Text)) {
				MessageBox::Show("Please enter a degree.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				// Clear the richTextBox
				richTextBox1->Clear();
				return;
				}
			 else if (!Int32::TryParse(txtDeg->Text, degree)) {
				MessageBox::Show("Please enter a valid degree.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				richTextBox1->Clear();
				return;
				}
			// Check if the degree is valid
			if (degree < 1 || degree > 10) {
				MessageBox::Show("Please enter a degree between 1 and 10.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				richTextBox1->Clear();
				return;
			}
			// Prepare vectors for x and y values
			std::vector<double> xValues;
			std::vector<double> yValues;
			EquationParser Parser;
			bool Flagx = true;
			bool Flagy = true;

			// Read X and Y values from DataGridView
			for (int i = 0; i < dataGridView1->Rows->Count - 1; i++) {
				if (dataGridView1->Rows[i]->Cells[0]->Value != nullptr &&
					dataGridView1->Rows[i]->Cells[1]->Value != nullptr) {
					try {
						/*double x = System::Convert::ToDouble(dataGridView1->Rows[i]->Cells[0]->Value);
						double y = System::Convert::ToDouble(dataGridView1->Rows[i]->Cells[1]->Value);*/

						System::String^ managedStrx = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
						double x = Helper::TableHandler(managedStrx, &Flagx);
						
						

						System::String^ managedStry = dataGridView1->Rows[i]->Cells[1]->Value->ToString();
						double y = Helper::TableHandler(managedStry, &Flagy);

						if (Flagy == false || Flagx == false)
						{
							MessageBox::Show("Invalid numeric value in row " + i, "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
							richTextBox1->Clear();
							return;
						}

						xValues.push_back(x);
						yValues.push_back(y);
					}
					catch (const std::exception& ex)
					{
						MessageBox::Show("An error occurred in row: " + i + gcnew System::String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						richTextBox1->Clear();
						return;
					}
				}
				else {
					MessageBox::Show("Please fill all X and Y values.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					richTextBox1->Clear();
					return;
				}
			}
			// Check number of points
			if (xValues.size() < 2 || xValues.size() > 20) {
				MessageBox::Show("Please enter at least 2 points and no more than 20.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				richTextBox1->Clear();
				return;
			}
			// Check for duplicate X values
			for (int i = 0; i < xValues.size(); i++) {
				for (int j = i + 1; j < xValues.size(); j++) {
					if (xValues[i] == xValues[j]) {
						MessageBox::Show("X values must be distinct (no duplicates).", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						richTextBox1->Clear();
						return;
					}
				}
			}
			// Create an instance of PolynomialFitter
			PolynomialFitter fitter(xValues, yValues, degree);
			// Fit the polynomial
			fitter.fit();
			// show result
			std::string result=fitter.show_Rseult();
			// Convert std::string to System::String^
			String^ output = gcnew String(result.c_str());
			richTextBox1->Clear();
			richTextBox1->AppendText("Polynomial Result:\n");
			richTextBox1->AppendText(output);
		}
		catch (const std::exception& ex) {
			MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (...) {
			MessageBox::Show("An error occurred: Unknown Error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void clear_Click(System::Object^ sender, System::EventArgs^ e) {
	txtDeg->Clear();
	dataGridView1->Rows->Clear();
	dataGridView1->Rows->Add();
	richTextBox1->Clear();
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void CurveFittingForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
