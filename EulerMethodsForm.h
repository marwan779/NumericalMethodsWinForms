#pragma once
#include "EulerMethods.h"
#include <msclr/marshal_cppstd.h>
#include<string>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EulerMethodsForm
	/// </summary>
	public ref class EulerMethodsForm : public System::Windows::Forms::Form
	{
	public:
		EulerMethodsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EulerMethodsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ Equation;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtX0;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtY0;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtH;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtSteps;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ Methods;

	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ calc;


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
			this->Equation = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtX0 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtY0 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtH = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtSteps = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Methods = (gcnew System::Windows::Forms::ComboBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->calc = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(54, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Equation";
			// 
			// Equation
			// 
			this->Equation->Location = System::Drawing::Point(122, 44);
			this->Equation->Name = L"Equation";
			this->Equation->Size = System::Drawing::Size(100, 24);
			this->Equation->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(64, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"x0";
			// 
			// txtX0
			// 
			this->txtX0->Location = System::Drawing::Point(122, 122);
			this->txtX0->Name = L"txtX0";
			this->txtX0->Size = System::Drawing::Size(100, 24);
			this->txtX0->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(309, 128);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"y0";
			// 
			// txtY0
			// 
			this->txtY0->Location = System::Drawing::Point(378, 122);
			this->txtY0->Name = L"txtY0";
			this->txtY0->Size = System::Drawing::Size(100, 24);
			this->txtY0->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(64, 181);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(16, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"h";
			// 
			// txtH
			// 
			this->txtH->Location = System::Drawing::Point(122, 181);
			this->txtH->Name = L"txtH";
			this->txtH->Size = System::Drawing::Size(100, 24);
			this->txtH->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(312, 199);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"steps";
			this->label5->Click += gcnew System::EventHandler(this, &EulerMethodsForm::label5_Click);
			// 
			// txtSteps
			// 
			this->txtSteps->Location = System::Drawing::Point(378, 191);
			this->txtSteps->Name = L"txtSteps";
			this->txtSteps->Size = System::Drawing::Size(100, 24);
			this->txtSteps->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(54, 267);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(60, 17);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Methods";
			this->label6->Click += gcnew System::EventHandler(this, &EulerMethodsForm::label6_Click);
			// 
			// Methods
			// 
			this->Methods->FormattingEnabled = true;
			this->Methods->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Euler", L"Euler Modified" });
			this->Methods->Location = System::Drawing::Point(122, 264);
			this->Methods->Name = L"Methods";
			this->Methods->Size = System::Drawing::Size(121, 24);
			this->Methods->TabIndex = 11;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(515, 61);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(404, 534);
			this->richTextBox1->TabIndex = 12;
			this->richTextBox1->Text = L"";
			// 
			// calc
			// 
			this->calc->Location = System::Drawing::Point(258, 455);
			this->calc->Name = L"calc";
			this->calc->Size = System::Drawing::Size(75, 23);
			this->calc->TabIndex = 13;
			this->calc->Text = L"calculate";
			this->calc->UseVisualStyleBackColor = true;
			this->calc->Click += gcnew System::EventHandler(this, &EulerMethodsForm::calc_Click);
			// 
			// EulerMethodsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(946, 692);
			this->Controls->Add(this->calc);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->Methods);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtSteps);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtH);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtY0);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtX0);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Equation);
			this->Controls->Add(this->label1);
			this->Name = L"EulerMethodsForm";
			this->Text = L"EulerMethodsForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void calc_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		double x0 ,y0,h;
		int steps;
		
		// Get inputs from TextBoxes
		std::string equation = msclr::interop::marshal_as<std::string>(Equation->Text);
		std::string method = msclr::interop::marshal_as<std::string>(Methods->Text);

		if (equation.empty()) {
			MessageBox::Show("Equation cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (!Double::TryParse(txtX0->Text,x0))
		{
			MessageBox::Show("X(0) must be Valid Number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!Double::TryParse(txtY0->Text, y0))
		{
			MessageBox::Show("Y(0) must be  Valid Number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (!Double::TryParse(txtH->Text, h))
		{
			MessageBox::Show("Step  must be Valid Number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (h <= 0) {
			MessageBox::Show("Step size must be greater than 0.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (!Int32::TryParse(txtSteps->Text, steps))
		{
			MessageBox::Show(" Number of Steps  must be Valid Number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;

		}
		
		if (steps <= 0) {
			MessageBox::Show("Number of steps must be greater than 0.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (Methods->SelectedIndex == -1)
		{
			MessageBox::Show("Please select a method first.", "Missing Selection", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		// Clear previous output
		richTextBox1->Clear();

		// Call the appropriate method
		if (method == "Euler") {
			BasicEuler solver;
			solver.solve(equation, x0, y0, h, steps);
		}
		else if (method == "Euler Modified") {
			ModifiedEuler solver;
			solver.solve(equation, x0, y0, h, steps);
		}
		// Show output in RichTextBox
		richTextBox1->Text = gcnew String(getEulerOutput().c_str());
	}
	catch (const std::exception& ex) {
		// Catch native C++ exceptions (e.g., from parser)
		MessageBox::Show("An error occurred: " + gcnew System::String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

    catch (Exception^ ex) { // Use a handle (^) instead of a reference (&)
      MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                
	}
	catch (...) {
		MessageBox::Show("An unknown error occurred.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
