#pragma once
#include "LagrangeInterpolator.h"
#include <vector>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <set>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LagrangeForm
	/// </summary>
	public ref class LagrangeForm : public System::Windows::Forms::Form
	{
	public:
		LagrangeForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			dataGridView1->ColumnCount = 2;
			dataGridView1->Rows->Clear();
			dataGridView1->Columns[0]->Name = "X";
			dataGridView1->Columns[1]->Name = "Y";
			dataGridView1->Rows->Add(nullptr, nullptr);
			// Set the default state of the text boxes
			txtX->Enabled = false;
			txtY->Enabled = false;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LagrangeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ calcX;
	private: System::Windows::Forms::RadioButton^ calcY;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtY;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtX;
	private: System::Windows::Forms::Button^ Calc;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;



	protected:

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->calcX = (gcnew System::Windows::Forms::RadioButton());
			this->calcY = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtY = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtX = (gcnew System::Windows::Forms::TextBox());
			this->Calc = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 252);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 26;
			this->dataGridView1->Size = System::Drawing::Size(374, 406);
			this->dataGridView1->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->calcX);
			this->groupBox1->Controls->Add(this->calcY);
			this->groupBox1->Location = System::Drawing::Point(37, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(210, 100);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"GroupBox for Calculation Type";
			// 
			// calcX
			// 
			this->calcX->AutoSize = true;
			this->calcX->Location = System::Drawing::Point(7, 62);
			this->calcX->Name = L"calcX";
			this->calcX->Size = System::Drawing::Size(176, 21);
			this->calcX->TabIndex = 1;
			this->calcX->TabStop = true;
			this->calcX->Text = L"Calculate X for a given Y";
			this->calcX->UseVisualStyleBackColor = true;
			this->calcX->CheckedChanged += gcnew System::EventHandler(this, &LagrangeForm::calcX_CheckedChanged);
			// 
			// calcY
			// 
			this->calcY->AutoSize = true;
			this->calcY->Location = System::Drawing::Point(7, 24);
			this->calcY->Name = L"calcY";
			this->calcY->Size = System::Drawing::Size(176, 21);
			this->calcY->TabIndex = 0;
			this->calcY->TabStop = true;
			this->calcY->Text = L"Calculate Y for a given X";
			this->calcY->UseVisualStyleBackColor = true;
			this->calcY->CheckedChanged += gcnew System::EventHandler(this, &LagrangeForm::calcY_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 142);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Y";
			// 
			// txtY
			// 
			this->txtY->Location = System::Drawing::Point(56, 139);
			this->txtY->Name = L"txtY";
			this->txtY->Size = System::Drawing::Size(100, 24);
			this->txtY->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 188);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"X";
			// 
			// txtX
			// 
			this->txtX->Location = System::Drawing::Point(56, 185);
			this->txtX->Name = L"txtX";
			this->txtX->Size = System::Drawing::Size(100, 24);
			this->txtX->TabIndex = 5;
			// 
			// Calc
			// 
			this->Calc->Location = System::Drawing::Point(403, 699);
			this->Calc->Name = L"Calc";
			this->Calc->Size = System::Drawing::Size(132, 40);
			this->Calc->TabIndex = 6;
			this->Calc->Text = L"Calculate";
			this->Calc->UseVisualStyleBackColor = true;
			this->Calc->Click += gcnew System::EventHandler(this, &LagrangeForm::Calc_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(492, 139);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(425, 519);
			this->richTextBox1->TabIndex = 7;
			this->richTextBox1->Text = L"";
			// 
			// LagrangeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(929, 844);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->Calc);
			this->Controls->Add(this->txtX);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtY);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"LagrangeForm";
			this->Text = L"LagrangeForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Calc_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Clear();
		std::vector<double> xValues, yValues;
		double yInput, xInput, xResult=0, yResult=0;
		try {
			// Check which radio button is selected
			if (!calcX->Checked && !calcY->Checked) {
				MessageBox::Show("Please select whether to calculate X or Y.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			
			// Read and validate input table
			for (int i = 0; i < dataGridView1->Rows->Count - 1; ++i) {
				auto row = dataGridView1->Rows[i];

				if (row->Cells[0]->Value == nullptr || row->Cells[1]->Value == nullptr) {
					MessageBox::Show("Missing value in row " + i, "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				try {
					double x = Convert::ToDouble(row->Cells[0]->Value);
					double y = Convert::ToDouble(row->Cells[1]->Value);
					xValues.push_back(x);
					yValues.push_back(y);
				}
				catch (...) {
					MessageBox::Show("Invalid numeric value in row " + i, "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
			}

			if (xValues.size() < 2) {
				MessageBox::Show("Please enter at least two data points.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// Check for duplicate x or y values
			std::set<double> XuniqueCheck;
			std::set<double> YuniqueCheck;


			for (double val : xValues) {  // Check duplicates in xValues
				if (!XuniqueCheck.insert(val).second) {
					MessageBox::Show("Duplicate X value found. Cannot interpolate.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
			}

			for (double val : yValues) {  // Check duplicates in yValues
				if (!YuniqueCheck.insert(val).second) {
					MessageBox::Show("Duplicate Y value found. Cannot interpolate.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
			}

			LagrangeInterpolator interpolator(xValues, yValues);

			try {
				if (calcX->Checked) {
					if (String::IsNullOrWhiteSpace(txtY->Text)) {
						MessageBox::Show("Please enter a value for Y.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
					else if (!Double::TryParse(txtY->Text, yInput))
					{	
						MessageBox::Show("Please enter a valid Y value to evaluate.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					double xResult = interpolator.interpolateInverse(yInput);
					richTextBox1->AppendText("Interpolated X = " + xResult.ToString("F6") + "\n");
				}
				else if (calcY->Checked) {
					if (String::IsNullOrWhiteSpace(txtX->Text)) {
						MessageBox::Show("Please enter a value for X.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}

					else if (!Double::TryParse(txtX->Text, xInput))
					{
						MessageBox::Show("Please enter a valid X value to evaluate.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					double yResult = interpolator.interpolateY(xInput);
					richTextBox1->AppendText("Interpolated Y = " + yResult.ToString("F6") + "\n");
				}
			}
			catch (const std::exception& e) {
				MessageBox::Show("Error: " + gcnew String(e.what()), "Computation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (...)
		{
			MessageBox::Show("An error occurred while processing the data.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void calcY_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (calcY->Checked) {
		txtX->Enabled = true;
		txtY->Enabled = false;
		txtX->Clear();

	}
}
private: System::Void calcX_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (calcX->Checked) {
		txtY->Enabled = true;
		txtX->Enabled = false;
		txtY->Clear();
	}
}
};
}
