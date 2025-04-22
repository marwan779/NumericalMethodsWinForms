#pragma once

#include "BisectionFrom.h"
#include "SecantForm.h"
#include "Newton.h"
#include "IntegrationForm.h"
#include "EulerMethodsForm.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;


	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;

	private: System::Windows::Forms::Button^ button10;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(146, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(487, 45);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Numerical Methods Calculator";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(112, 148);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 60);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Bisection";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(286, 148);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 60);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Secant";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(466, 148);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(126, 60);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Integration";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(136, 239);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(184, 60);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Lagrange Interpolation";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(382, 239);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(184, 60);
			this->button7->TabIndex = 7;
			this->button7->Text = L"Newton Interpolation";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(112, 331);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(200, 60);
			this->button8->TabIndex = 8;
			this->button8->Text = L"Euler and Euler Modified";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button10->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(437, 331);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(155, 60);
			this->button10->TabIndex = 10;
			this->button10->Text = L"Curve Fiting";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(788, 596);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:

		System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Project1::BisectionFrom^ bisectionForm = gcnew Project1::BisectionFrom();
		bisectionForm->Show();
		// this->Hide(); // Uncomment if you want to hide MyForm
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Project1::SecantFrom^ secantFrom = gcnew Project1::SecantFrom();
		secantFrom->Show();
		// this->Hide(); // Uncomment if you want to hide MyForm
	}

	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		// Open the Newton Interpolation form
		Project1::Newton^ Newton = gcnew Project1::Newton();
		Newton->Show();
		// this->Hide(); // Uncomment if you want to hide MyForm
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		// Open the Integration form
		  Project1::IntegrationForm^ integrationForm = gcnew Project1::IntegrationForm();
		   integrationForm->Show();
		// this->Hide(); // Uncomment if you want to hide MyForm
	}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	// Open the Euler and Euler Modified form
	Project1::EulerMethodsForm^ eulerMethodsForm = gcnew Project1::EulerMethodsForm();
	eulerMethodsForm->Show();
	// this->Hide(); // Uncomment if you want to hide MyForm
}
};


}
