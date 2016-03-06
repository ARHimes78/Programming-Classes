#pragma once
#include "simplecalc.h"

namespace HimesE3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	SimpleCalc calc;
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::TextBox^  txtOperand1;
	private: System::Windows::Forms::TextBox^  txtOperand2;
	private: System::Windows::Forms::TextBox^  txtResults;
	private: System::Windows::Forms::Button^  btAdd;
	private: System::Windows::Forms::Button^  btSubtr;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::Button^  btMult;
	private: System::Windows::Forms::Button^  btnDiv;
	private: System::Windows::Forms::Label^  lblOperation;
	private: System::Windows::Forms::Label^  lblEquals;
	private: System::Windows::Forms::Label^  Title;
	protected: 

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
			this->txtOperand1 = (gcnew System::Windows::Forms::TextBox());
			this->txtOperand2 = (gcnew System::Windows::Forms::TextBox());
			this->txtResults = (gcnew System::Windows::Forms::TextBox());
			this->btAdd = (gcnew System::Windows::Forms::Button());
			this->btSubtr = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btMult = (gcnew System::Windows::Forms::Button());
			this->btnDiv = (gcnew System::Windows::Forms::Button());
			this->lblOperation = (gcnew System::Windows::Forms::Label());
			this->lblEquals = (gcnew System::Windows::Forms::Label());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtOperand1
			// 
			this->txtOperand1->Location = System::Drawing::Point(52, 102);
			this->txtOperand1->Name = L"txtOperand1";
			this->txtOperand1->Size = System::Drawing::Size(100, 20);
			this->txtOperand1->TabIndex = 1;
			// 
			// txtOperand2
			// 
			this->txtOperand2->Location = System::Drawing::Point(200, 102);
			this->txtOperand2->Name = L"txtOperand2";
			this->txtOperand2->Size = System::Drawing::Size(100, 20);
			this->txtOperand2->TabIndex = 2;
			// 
			// txtResults
			// 
			this->txtResults->Location = System::Drawing::Point(353, 102);
			this->txtResults->Name = L"txtResults";
			this->txtResults->Size = System::Drawing::Size(100, 20);
			this->txtResults->TabIndex = 3;
			// 
			// btAdd
			// 
			this->btAdd->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btAdd->Location = System::Drawing::Point(52, 185);
			this->btAdd->Name = L"btAdd";
			this->btAdd->Size = System::Drawing::Size(75, 23);
			this->btAdd->TabIndex = 4;
			this->btAdd->Text = L"+";
			this->btAdd->UseVisualStyleBackColor = true;
			this->btAdd->Click += gcnew System::EventHandler(this, &Form1::btAdd_Click);
			// 
			// btSubtr
			// 
			this->btSubtr->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btSubtr->Location = System::Drawing::Point(200, 185);
			this->btSubtr->Name = L"btSubtr";
			this->btSubtr->Size = System::Drawing::Size(75, 23);
			this->btSubtr->TabIndex = 5;
			this->btSubtr->Text = L"-";
			this->btSubtr->UseVisualStyleBackColor = true;
			this->btSubtr->Click += gcnew System::EventHandler(this, &Form1::btSubtr_Click);
			// 
			// btnClear
			// 
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnClear->Location = System::Drawing::Point(353, 235);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 6;
			this->btnClear->Text = L"CLEAR";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &Form1::btnClear_Click);
			// 
			// btMult
			// 
			this->btMult->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btMult->Location = System::Drawing::Point(51, 281);
			this->btMult->Name = L"btMult";
			this->btMult->Size = System::Drawing::Size(75, 23);
			this->btMult->TabIndex = 7;
			this->btMult->Text = L"*";
			this->btMult->UseVisualStyleBackColor = true;
			this->btMult->Click += gcnew System::EventHandler(this, &Form1::btMult_Click);
			// 
			// btnDiv
			// 
			this->btnDiv->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnDiv->Location = System::Drawing::Point(200, 281);
			this->btnDiv->Name = L"btnDiv";
			this->btnDiv->Size = System::Drawing::Size(75, 23);
			this->btnDiv->TabIndex = 8;
			this->btnDiv->Text = L"/";
			this->btnDiv->UseVisualStyleBackColor = true;
			this->btnDiv->Click += gcnew System::EventHandler(this, &Form1::btnDiv_Click);
			// 
			// lblOperation
			// 
			this->lblOperation->AutoSize = true;
			this->lblOperation->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblOperation->Location = System::Drawing::Point(169, 103);
			this->lblOperation->Name = L"lblOperation";
			this->lblOperation->Size = System::Drawing::Size(13, 19);
			this->lblOperation->TabIndex = 9;
			this->lblOperation->Text = L" ";
			// 
			// lblEquals
			// 
			this->lblEquals->AutoSize = true;
			this->lblEquals->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblEquals->Location = System::Drawing::Point(318, 103);
			this->lblEquals->Name = L"lblEquals";
			this->lblEquals->Size = System::Drawing::Size(18, 19);
			this->lblEquals->TabIndex = 10;
			this->lblEquals->Text = L"=";
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(47, 21);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(408, 38);
			this->Title->TabIndex = 11;
			this->Title->Text = L"           Welcome to the C++ Simple Calculator\r\nEnter two numbers and press the " 
				L"appropriate button\r\n";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PaleTurquoise;
			this->ClientSize = System::Drawing::Size(508, 346);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->lblEquals);
			this->Controls->Add(this->lblOperation);
			this->Controls->Add(this->btnDiv);
			this->Controls->Add(this->btMult);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btSubtr);
			this->Controls->Add(this->btAdd);
			this->Controls->Add(this->txtResults);
			this->Controls->Add(this->txtOperand2);
			this->Controls->Add(this->txtOperand1);
			this->Name = L"Form1";
			this->Text = L"Alan Himes E3 Simple Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btAdd_Click(System::Object^  sender, System::EventArgs^  e) {
			 double op1 = Convert::ToDouble(txtOperand1->Text);
			 double op2 = Convert::ToDouble(txtOperand2->Text);

			 calc.SetOperation('+', op1, op2);
			 txtResults->Text = calc.GetAnswer().ToString();

			 lblOperation->Text = "+";
			 }
private: System::Void btSubtr_Click(System::Object^  sender, System::EventArgs^  e) {
			 double op1 = Convert::ToDouble(txtOperand1->Text);
			 double op2 = Convert::ToDouble(txtOperand2->Text);

			 calc.SetOperation('-', op1, op2);
			 txtResults->Text = calc.GetAnswer().ToString();

			 lblOperation->Text = "-";
		 }
private: System::Void btMult_Click(System::Object^  sender, System::EventArgs^  e) {
			 double op1 = Convert::ToDouble(txtOperand1->Text);
			 double op2 = Convert::ToDouble(txtOperand2->Text);

			 calc.SetOperation('*', op1, op2);
			 txtResults->Text = calc.GetAnswer().ToString();

			 lblOperation->Text = "*";
		 }
private: System::Void btnDiv_Click(System::Object^  sender, System::EventArgs^  e) {
		     double op1 = Convert::ToDouble(txtOperand1->Text);
			 double op2 = Convert::ToDouble(txtOperand2->Text);

			 if (op2 == 0)
				 txtResults->Text = "Divide by 0!";
			 else {

				calc.SetOperation('/', op1, op2);
				txtResults->Text = calc.GetAnswer().ToString();
			 }

			 lblOperation->Text = "/";
		 }
private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) {
			 txtOperand1->Clear();
			 txtOperand2->Clear();
			 txtResults->Clear();
			 lblOperation->Text = "";
		 }
};
}