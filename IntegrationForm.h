#pragma once
#include <string>
#include "Integration.h"
#include <msclr/marshal_cppstd.h>
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
	/// Summary for IntegrationForm
	/// </summary>
	public ref class IntegrationForm : public System::Windows::Forms::Form
	{

	public:
		IntegrationForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			dataGridTable->ColumnCount = 2;
			dataGridTable->Rows->Clear();
			dataGridTable->Columns[0]->Name = "X";
			dataGridTable->Columns[1]->Name = "Y";
			dataGridTable->Rows->Add(nullptr, nullptr);
			txtN->Enabled = false;
			Equation->Enabled = false;
			//
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~IntegrationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ Table_choise;
	private: System::Windows::Forms::RadioButton^ AddButton;
	private: System::Windows::Forms::RadioButton^ GenerateButton;
	protected:

	protected:



	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::DataGridView^ dataGridTable;
	private: System::Windows::Forms::CheckedListBox^ MethodTable;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtA;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtB;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ Equation;







	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtN;
	private: System::Windows::Forms::Button^ calculate;
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
			this->Table_choise = (gcnew System::Windows::Forms::GroupBox());
			this->AddButton = (gcnew System::Windows::Forms::RadioButton());
			this->GenerateButton = (gcnew System::Windows::Forms::RadioButton());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->dataGridTable = (gcnew System::Windows::Forms::DataGridView());
			this->MethodTable = (gcnew System::Windows::Forms::CheckedListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtA = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtB = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->Equation = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtN = (gcnew System::Windows::Forms::TextBox());
			this->calculate = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->Table_choise->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridTable))->BeginInit();
			this->SuspendLayout();
			// 
			// Table_choise
			// 
			this->Table_choise->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Table_choise->Controls->Add(this->AddButton);
			this->Table_choise->Controls->Add(this->GenerateButton);
			this->Table_choise->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Table_choise->Location = System::Drawing::Point(41, 103);
			this->Table_choise->Name = L"Table_choise";
			this->Table_choise->Size = System::Drawing::Size(328, 140);
			this->Table_choise->TabIndex = 0;
			this->Table_choise->TabStop = false;
			this->Table_choise->Text = L"Table_choise";
			this->Table_choise->Enter += gcnew System::EventHandler(this, &IntegrationForm::Table_choise_Enter);
			// 
			// AddButton
			// 
			this->AddButton->AutoSize = true;
			this->AddButton->Checked = true;
			this->AddButton->Location = System::Drawing::Point(22, 83);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(171, 38);
			this->AddButton->TabIndex = 0;
			this->AddButton->TabStop = true;
			this->AddButton->Text = L"Add values";
			this->AddButton->UseVisualStyleBackColor = true;
			// 
			// GenerateButton
			// 
			this->GenerateButton->AutoSize = true;
			this->GenerateButton->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->GenerateButton->Location = System::Drawing::Point(22, 39);
			this->GenerateButton->Name = L"GenerateButton";
			this->GenerateButton->Size = System::Drawing::Size(219, 38);
			this->GenerateButton->TabIndex = 0;
			this->GenerateButton->Text = L"Generate table";
			this->GenerateButton->UseVisualStyleBackColor = true;
			this->GenerateButton->CheckedChanged += gcnew System::EventHandler(this, &IntegrationForm::radioButton1_CheckedChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(850, 103);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(423, 552);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// dataGridTable
			// 
			this->dataGridTable->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataGridTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridTable->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridTable->Location = System::Drawing::Point(41, 264);
			this->dataGridTable->Name = L"dataGridTable";
			this->dataGridTable->RowHeadersWidth = 51;
			this->dataGridTable->RowTemplate->Height = 26;
			this->dataGridTable->Size = System::Drawing::Size(328, 457);
			this->dataGridTable->TabIndex = 2;
			// 
			// MethodTable
			// 
			this->MethodTable->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->MethodTable->BackColor = System::Drawing::Color::LightSteelBlue;
			this->MethodTable->CheckOnClick = true;
			this->MethodTable->Font = (gcnew System::Drawing::Font(L"Tahoma", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MethodTable->FormattingEnabled = true;
			this->MethodTable->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Simpson 1/3", L"Simpson 3/8", L"Trapezoidal" });
			this->MethodTable->Location = System::Drawing::Point(397, 312);
			this->MethodTable->Name = L"MethodTable";
			this->MethodTable->Size = System::Drawing::Size(402, 181);
			this->MethodTable->TabIndex = 3;
			this->MethodTable->SelectedIndexChanged += gcnew System::EventHandler(this, &IntegrationForm::checkedListBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(505, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 36);
			this->label1->TabIndex = 4;
			this->label1->Text = L"a";
			// 
			// txtA
			// 
			this->txtA->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txtA->Location = System::Drawing::Point(541, 68);
			this->txtA->Name = L"txtA";
			this->txtA->Size = System::Drawing::Size(100, 24);
			this->txtA->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(508, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 36);
			this->label3->TabIndex = 6;
			this->label3->Text = L"b";
			// 
			// txtB
			// 
			this->txtB->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txtB->Location = System::Drawing::Point(541, 110);
			this->txtB->Name = L"txtB";
			this->txtB->Size = System::Drawing::Size(100, 24);
			this->txtB->TabIndex = 7;
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(41, 64);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(101, 28);
			this->label12->TabIndex = 8;
			this->label12->Text = L"Equation";
			// 
			// Equation
			// 
			this->Equation->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Equation->Location = System::Drawing::Point(148, 68);
			this->Equation->Name = L"Equation";
			this->Equation->Size = System::Drawing::Size(100, 24);
			this->Equation->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(508, 144);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 36);
			this->label2->TabIndex = 11;
			this->label2->Text = L"n";
			this->label2->Click += gcnew System::EventHandler(this, &IntegrationForm::label2_Click);
			// 
			// txtN
			// 
			this->txtN->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txtN->Location = System::Drawing::Point(541, 156);
			this->txtN->Name = L"txtN";
			this->txtN->Size = System::Drawing::Size(100, 24);
			this->txtN->TabIndex = 12;
			// 
			// calculate
			// 
			this->calculate->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->calculate->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->calculate->Location = System::Drawing::Point(476, 638);
			this->calculate->Name = L"calculate";
			this->calculate->Size = System::Drawing::Size(270, 93);
			this->calculate->TabIndex = 13;
			this->calculate->Text = L"Calc";
			this->calculate->UseVisualStyleBackColor = true;
			this->calculate->Click += gcnew System::EventHandler(this, &IntegrationForm::calculate_Click);
			// 
			// clear
			// 
			this->clear->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clear->Location = System::Drawing::Point(46, 728);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(107, 39);
			this->clear->TabIndex = 14;
			this->clear->Text = L"clear";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &IntegrationForm::button1_Click);
			// 
			// IntegrationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1285, 779);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->calculate);
			this->Controls->Add(this->txtN);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Equation);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->txtB);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtA);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MethodTable);
			this->Controls->Add(this->dataGridTable);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->Table_choise);
			this->Name = L"IntegrationForm";
			this->Text = L"IntegrationForm";
			this->Table_choise->ResumeLayout(false);
			this->Table_choise->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridTable))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (GenerateButton->Checked) {
			dataGridTable->Enabled = false;
			txtN->Enabled = true;
			Equation->Enabled = true;
		}
		else {
			dataGridTable->Enabled = true;
			Equation->Enabled = false;
			txtN->Enabled = false;
		}
	}
	private: System::Void Table_choise_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void calculate_Click(System::Object^ sender, System::EventArgs^ e) {
	using namespace msclr::interop;

	NumericalIntegrator integrator;
	EquationParser Parser;


	try {
		// Get the input from TextBoxes and convert to std::string
		std::string eq = msclr::interop::marshal_as<std::string>(Equation->Text);
		std::string a = marshal_as<std::string>(txtA->Text);
		std::string b = marshal_as<std::string>(txtB->Text);
		bool Flagx = true;
		bool Flagy = true;

		
		// Check if a or b contains variables like x or y
		if (a.find("x") != std::string::npos || a.find("y") != std::string::npos|| 
			b.find("x")!=std::string::npos||b.find("y")!= std::string::npos) {
			MessageBox::Show("Please enter valid numeric values for a and b.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else {
			integrator.setBoundsFromText(a, b);
		}

		// If user chose to generate values
		if (GenerateButton->Checked) {
			try {
				// Set equation 

				integrator.setEquation(eq);
				int points = System::Convert::ToInt32(txtN->Text);
				points = points + 1;
				integrator.setPoints(points);
				integrator.generateTable();
			}
			catch (System::FormatException^ ex) {
				MessageBox::Show("Please enter a valid number of points.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			
		}
		// If user entered values manually in the table
		else {
			std::vector<std::pair<double, double>> table;

			for (int i = 0; i < dataGridTable->Rows->Count - 1; i++) {
				if (dataGridTable->Rows[i]->Cells[0]->Value != nullptr &&
					dataGridTable->Rows[i]->Cells[1]->Value != nullptr) {
					try {
						System::String^ managedStrx = dataGridTable->Rows[i]->Cells[0]->Value->ToString();
						double x = Helper::TableHandler(managedStrx, &Flagx);

						System::String^ managedStry = dataGridTable->Rows[i]->Cells[1]->Value->ToString();
						double y = Helper::TableHandler(managedStry, &Flagy);

						if (Flagy == false || Flagx == false)
						{
							MessageBox::Show("Invalid numeric value in row " + i, "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
							return;
						}

						table.push_back({ x, y });
					}
					catch (const std::exception& ex)
					{
						MessageBox::Show("An error occurred in row: " + i+ " , " + gcnew System::String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return;
					}
					
				}
				else {
					MessageBox::Show("Please fill all X and Y values.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
			}

			integrator.loadTable(table);
		}

		// Clear previous results
		richTextBox1->Clear();
		bool any_checked = false;


		// Loop through checked items and apply selected integration methods
		for (int i = 0; i < MethodTable->Items->Count; i++) {
			if (MethodTable->GetItemChecked(i)) {
				any_checked = true;
				System::String^ methodName = MethodTable->Items[i]->ToString();
				double result = 0;

				if (methodName == "Trapezoidal") {
					result = integrator.trapezoidalRule();
					richTextBox1->AppendText("Trapezoidal Rule = " + result.ToString() + "\n");
				}
				else if (methodName == "Simpson 1/3") {
					result = integrator.simpsons13Rule();
					richTextBox1->AppendText("Simpson's 1/3 Rule = " + result.ToString() + "\n");
				}
				else if (methodName == "Simpson 3/8") {
					result = integrator.simpsons38Rule();
					richTextBox1->AppendText("Simpson's 3/8 Rule = " + result.ToString() + "\n");
				}
			}
		}
		if (!any_checked) {
			MessageBox::Show("Please select at least one method.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		

	}
	catch (const std::exception& e) {

		MessageBox::Show("An error occurred: " + gcnew System::String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	catch (...)
	{
		MessageBox::Show("An error occurred: " + gcnew System::String("Unknown Error"), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

};
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Clear all text boxes and data grid
	txtA->Clear();
	txtB->Clear();
	Equation->Clear();
	dataGridTable->Rows->Clear();
	dataGridTable->Rows->Add();
	richTextBox1->Clear();
}
};
}


