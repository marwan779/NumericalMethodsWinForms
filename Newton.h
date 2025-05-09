#pragma once
#include <vector>
#include<iostream>
#include<msclr/marshal_cppstd.h>
#include "DividedDifferenceInterpolator.h"
#include "Parser.h"
#include "Helper.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class Newton : public System::Windows::Forms::Form
	{
	public:
		Newton(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			dataGrid->ColumnCount = 2;
			dataGrid->Rows->Clear();
			dataGrid->Columns[0]->Name = "X";
			dataGrid->Columns[1]->Name = "Y";
			dataGrid->Rows->Add(nullptr, nullptr);
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Newton()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::DataGridView^ dataGrid;
	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ xx_value;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->xx_value = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(106, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(158, 34);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Points table";
			this->label1->Click += gcnew System::EventHandler(this, &Newton::label1_Click);
			// 
			// dataGrid
			// 
			this->dataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid->Location = System::Drawing::Point(14, 75);
			this->dataGrid->Name = L"dataGrid";
			this->dataGrid->RowHeadersWidth = 51;
			this->dataGrid->RowTemplate->Height = 26;
			this->dataGrid->Size = System::Drawing::Size(337, 473);
			this->dataGrid->TabIndex = 3;
			this->dataGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Newton::dataGrid_CellContentClick);
			// 
			// btnSubmit
			// 
			this->btnSubmit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubmit->Location = System::Drawing::Point(89, 655);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(116, 58);
			this->btnSubmit->TabIndex = 4;
			this->btnSubmit->Text = L"run";
			this->btnSubmit->UseVisualStyleBackColor = true;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &Newton::btnSubmit_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 605);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 34);
			this->label2->TabIndex = 5;
			this->label2->Text = L"x value";
			this->label2->Click += gcnew System::EventHandler(this, &Newton::label2_Click);
			// 
			// xx_value
			// 
			this->xx_value->Location = System::Drawing::Point(112, 615);
			this->xx_value->Name = L"xx_value";
			this->xx_value->Size = System::Drawing::Size(142, 23);
			this->xx_value->TabIndex = 6;
			this->xx_value->TextChanged += gcnew System::EventHandler(this, &Newton::xx_value_TextChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->richTextBox1->BackColor = System::Drawing::SystemColors::Info;
			this->richTextBox1->Enabled = false;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::InfoText;
			this->richTextBox1->Location = System::Drawing::Point(630, 55);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(607, 658);
			this->richTextBox1->TabIndex = 7;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Newton::richTextBox1_TextChanged);
			// 
			// Newton
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1249, 767);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->xx_value);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnSubmit);
			this->Controls->Add(this->dataGrid);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"Newton";
			this->Text = L"MyForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
		std::vector<double> xValues;
		std::vector<double> yValues;
		EquationParser Parser;
		bool Flagx = true;
		bool Flagy = true;

		try
		{
			for (int i = 0; i < dataGrid->Rows->Count - 1; i++) {
				if (dataGrid->Rows[i]->Cells[0]->Value != nullptr &&
					dataGrid->Rows[i]->Cells[1]->Value != nullptr) {
					try {
						System::String^ managedStrx = dataGrid->Rows[i]->Cells[0]->Value->ToString();
						double x = Helper::TableHandler(managedStrx, &Flagx);

						System::String^ managedStry = dataGrid->Rows[i]->Cells[1]->Value->ToString();
						double y = Helper::TableHandler(managedStry, &Flagy);

						if (Flagy == false || Flagx == false)
						{
							MessageBox::Show("Invalid numeric value in row " + i, "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
							richTextBox1->Clear();
						}
						xValues.push_back(x);
						yValues.push_back(y);
					}
					catch (const std::exception& ex)
					{
						MessageBox::Show("An error occurred in row: " + i + " " + gcnew System::String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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

			// Parse the xx value
			double xx;
			if (!Double::TryParse(xx_value->Text, xx)) {
				MessageBox::Show("Please enter a valid X value to evaluate.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				richTextBox1->Clear();
				return;
			}

			// All input is valid → perform interpolation
			richTextBox1->Clear();
			divide interpolator;
			interpolator.setData(xValues, yValues, xx, richTextBox1);
		}
		catch (const std::exception&)
		{
			MessageBox::Show("An error happened when parsing the equation, Make sure to enter a vaild equation.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			richTextBox1->Clear();
		}
		catch (...)
		{
			MessageBox::Show("An unexpected error occurred.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			richTextBox1->Clear();
		}
		// Read X and Y values from DataGridView


	}

	private: System::Void dataGrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void xx_value_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
