//Alan Himes
//ahimes1@cnm.edu
//form1.h

//I'm sorry to do this again, but please ignore the Blackboard upload. -AH

#pragma once

#include <sstream>
#include "UtilityFunctions.h"
#include "enigma.h"
#include "primeshift.h"
#include "shifty.h"
#include "qwerty.h"

namespace HimesP8 {

	using namespace System::Windows::Forms;//for popup window if no message has been entered.
	using namespace System::IO;//for StreamWriter^ and StreamReader^

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Summary for Form1
	/// </summary>
	
	Enigma *pE[3];

	Primeshift pse;
	Shifty se;
	Qwerty qe;

	int index = 0;
	string encodeType = "Prime Shift";

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
	private: System::Windows::Forms::Label^  labelTitle;
	protected: 
	private: System::Windows::Forms::Label^  labelInstructions;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  labelMessage;
	private: System::Windows::Forms::TextBox^  textBoxMessage;
	private: System::Windows::Forms::RadioButton^  radioEnterKey;
	private: System::Windows::Forms::RadioButton^  radioRandomKey;
	private: System::Windows::Forms::NumericUpDown^  NUDKey;
	private: System::Windows::Forms::RichTextBox^  richTextBoxSummary;

	private: System::Windows::Forms::Button^  buttonEnc;
	private: System::Windows::Forms::Button^  buttonDec;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  buttonClear;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioShifty;

	private: System::Windows::Forms::RadioButton^  radioPrime;
	private: System::Windows::Forms::RadioButton^  radioQwerty;
	private: System::Windows::Forms::Label^  label1;







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
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelInstructions = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelMessage = (gcnew System::Windows::Forms::Label());
			this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
			this->radioEnterKey = (gcnew System::Windows::Forms::RadioButton());
			this->radioRandomKey = (gcnew System::Windows::Forms::RadioButton());
			this->NUDKey = (gcnew System::Windows::Forms::NumericUpDown());
			this->richTextBoxSummary = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonEnc = (gcnew System::Windows::Forms::Button());
			this->buttonDec = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioQwerty = (gcnew System::Windows::Forms::RadioButton());
			this->radioShifty = (gcnew System::Windows::Forms::RadioButton());
			this->radioPrime = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDKey))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(304, 27);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(177, 24);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Enigma generator";
			// 
			// labelInstructions
			// 
			this->labelInstructions->AutoSize = true;
			this->labelInstructions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelInstructions->Location = System::Drawing::Point(168, 63);
			this->labelInstructions->Name = L"labelInstructions";
			this->labelInstructions->Size = System::Drawing::Size(442, 32);
			this->labelInstructions->TabIndex = 1;
			this->labelInstructions->Text = L"Enter a message, set a key and click encode \r\nor click decode to open an encrypte" 
				L"d message to be decoded.";
			this->labelInstructions->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(277, 351);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(227, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Secret message results";
			// 
			// labelMessage
			// 
			this->labelMessage->AutoSize = true;
			this->labelMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelMessage->Location = System::Drawing::Point(12, 149);
			this->labelMessage->Name = L"labelMessage";
			this->labelMessage->Size = System::Drawing::Size(226, 20);
			this->labelMessage->TabIndex = 3;
			this->labelMessage->Text = L"Enter secret message here";
			// 
			// textBoxMessage
			// 
			this->textBoxMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxMessage->Location = System::Drawing::Point(16, 173);
			this->textBoxMessage->Name = L"textBoxMessage";
			this->textBoxMessage->Size = System::Drawing::Size(737, 26);
			this->textBoxMessage->TabIndex = 4;
			// 
			// radioEnterKey
			// 
			this->radioEnterKey->AutoSize = true;
			this->radioEnterKey->Checked = true;
			this->radioEnterKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioEnterKey->Location = System::Drawing::Point(16, 221);
			this->radioEnterKey->Name = L"radioEnterKey";
			this->radioEnterKey->Size = System::Drawing::Size(147, 17);
			this->radioEnterKey->TabIndex = 5;
			this->radioEnterKey->TabStop = true;
			this->radioEnterKey->Text = L"Choose a key number";
			this->radioEnterKey->UseVisualStyleBackColor = true;
			this->radioEnterKey->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioEnterKey_CheckedChanged);
			// 
			// radioRandomKey
			// 
			this->radioRandomKey->AutoSize = true;
			this->radioRandomKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioRandomKey->Location = System::Drawing::Point(16, 244);
			this->radioRandomKey->Name = L"radioRandomKey";
			this->radioRandomKey->Size = System::Drawing::Size(169, 17);
			this->radioRandomKey->TabIndex = 6;
			this->radioRandomKey->Text = L"Randomly generate a key";
			this->radioRandomKey->UseVisualStyleBackColor = true;
			this->radioRandomKey->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioRandomKey_CheckedChanged);
			// 
			// NUDKey
			// 
			this->NUDKey->Location = System::Drawing::Point(191, 221);
			this->NUDKey->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->NUDKey->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NUDKey->Name = L"NUDKey";
			this->NUDKey->Size = System::Drawing::Size(47, 20);
			this->NUDKey->TabIndex = 7;
			this->NUDKey->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// richTextBoxSummary
			// 
			this->richTextBoxSummary->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBoxSummary->Location = System::Drawing::Point(56, 391);
			this->richTextBoxSummary->Name = L"richTextBoxSummary";
			this->richTextBoxSummary->ReadOnly = true;
			this->richTextBoxSummary->Size = System::Drawing::Size(662, 124);
			this->richTextBoxSummary->TabIndex = 8;
			this->richTextBoxSummary->Text = L"";
			// 
			// buttonEnc
			// 
			this->buttonEnc->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonEnc->Location = System::Drawing::Point(56, 281);
			this->buttonEnc->Name = L"buttonEnc";
			this->buttonEnc->Size = System::Drawing::Size(200, 50);
			this->buttonEnc->TabIndex = 9;
			this->buttonEnc->Text = L"Encode";
			this->buttonEnc->UseVisualStyleBackColor = true;
			this->buttonEnc->Click += gcnew System::EventHandler(this, &Form1::buttonEnc_Click);
			// 
			// buttonDec
			// 
			this->buttonDec->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonDec->Location = System::Drawing::Point(518, 281);
			this->buttonDec->Name = L"buttonDec";
			this->buttonDec->Size = System::Drawing::Size(200, 50);
			this->buttonDec->TabIndex = 10;
			this->buttonDec->Text = L"Decode";
			this->buttonDec->UseVisualStyleBackColor = true;
			this->buttonDec->Click += gcnew System::EventHandler(this, &Form1::buttonDec_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// buttonClear
			// 
			this->buttonClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonClear->Location = System::Drawing::Point(642, 521);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(75, 23);
			this->buttonClear->TabIndex = 11;
			this->buttonClear->Text = L"CLEAR";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->radioQwerty);
			this->groupBox1->Controls->Add(this->radioShifty);
			this->groupBox1->Controls->Add(this->radioPrime);
			this->groupBox1->Location = System::Drawing::Point(273, 205);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(231, 143);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(6, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(213, 16);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Choose an encryption method\r\n";
			// 
			// radioQwerty
			// 
			this->radioQwerty->AutoSize = true;
			this->radioQwerty->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioQwerty->Location = System::Drawing::Point(6, 91);
			this->radioQwerty->Name = L"radioQwerty";
			this->radioQwerty->Size = System::Drawing::Size(64, 17);
			this->radioQwerty->TabIndex = 2;
			this->radioQwerty->TabStop = true;
			this->radioQwerty->Text = L"Qwerty";
			this->radioQwerty->UseVisualStyleBackColor = true;
			this->radioQwerty->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioQwerty_CheckedChanged);
			// 
			// radioShifty
			// 
			this->radioShifty->AutoSize = true;
			this->radioShifty->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioShifty->Location = System::Drawing::Point(6, 67);
			this->radioShifty->Name = L"radioShifty";
			this->radioShifty->Size = System::Drawing::Size(57, 17);
			this->radioShifty->TabIndex = 1;
			this->radioShifty->TabStop = true;
			this->radioShifty->Text = L"Shifty";
			this->radioShifty->UseVisualStyleBackColor = true;
			this->radioShifty->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioShifty_CheckedChanged);
			// 
			// radioPrime
			// 
			this->radioPrime->AutoSize = true;
			this->radioPrime->Checked = true;
			this->radioPrime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioPrime->Location = System::Drawing::Point(6, 44);
			this->radioPrime->Name = L"radioPrime";
			this->radioPrime->Size = System::Drawing::Size(86, 17);
			this->radioPrime->TabIndex = 0;
			this->radioPrime->TabStop = true;
			this->radioPrime->Text = L"Prime Shift";
			this->radioPrime->UseVisualStyleBackColor = true;
			this->radioPrime->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioPrime_CheckedChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->buttonDec);
			this->Controls->Add(this->buttonEnc);
			this->Controls->Add(this->richTextBoxSummary);
			this->Controls->Add(this->NUDKey);
			this->Controls->Add(this->radioRandomKey);
			this->Controls->Add(this->radioEnterKey);
			this->Controls->Add(this->textBoxMessage);
			this->Controls->Add(this->labelMessage);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->labelInstructions);
			this->Controls->Add(this->labelTitle);
			this->Name = L"Form1";
			this->Text = L"Program 7 - Enigma on a Form";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDKey))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		

	private: System::Void radioEnterKey_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 NUDKey->Enabled = true;
			 }
private: System::Void radioRandomKey_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 NUDKey->Enabled = false;
		 }
private: System::Void buttonEnc_Click(System::Object^  sender, System::EventArgs^  e) {
                pE[0] = &pse;
	            pE[1] = &se;
	            pE[2] = &qe;
			 if (textBoxMessage->Text == "") {
				string noMessage = "Enter a message to encode!";
				String^ noMsgError = gcnew String(noMessage.c_str());
				MessageBox::Show(noMsgError);
			}
			 else {
				 string message;
				 int key;

				 To_string(textBoxMessage->Text, message);

				 if (radioEnterKey->Checked) {
					 
					 key = Decimal::ToInt32(NUDKey->Value);
					 pE[index]->SetMessage(message, key);
				 }
				 else {

					 pE[index]->SetMessage(message);//random number 1-50 is generated and assigned to enigma's key
					 key = pE[index]->GetKey();

				 }

				 stringstream ssSummary;

				 string encoded, decoded;

				 ssSummary << "Message: \"" << pE[index]->GetDecodedMessage() << "\"" << endl;
				 ssSummary << "Encoded Message: \"" << pE[index]->GetCodedMessage() << "\"" << endl;
				 ssSummary << "Key: " << key << endl;;//key was assigned a value from whichever radio button selection.
				 ssSummary << "Encryption: " << encodeType;
				 
				 richTextBoxSummary->Text = gcnew String(ssSummary.str().c_str());

				 //Save to file:

				 if (saveFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK) {

					saveFileDialog1->InitialDirectory = "\\";
					saveFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
					saveFileDialog1->DefaultExt = "txt";
					saveFileDialog1->FilterIndex = 2;
					saveFileDialog1->RestoreDirectory = true;
					
					//saveFileDialog1->FileName = "text.txt";
					StreamWriter^ output = gcnew StreamWriter(saveFileDialog1->FileName);
					
					output->WriteLine(gcnew String(pE[index]->GetCodedMessage().c_str()));
					output->WriteLine(pE[index]->GetKey().ToString());
					output->WriteLine(index);//Additional line added to the file for encoding type.
					output->Close();

				 }
				 else {
				 richTextBoxSummary->Text="No file opened.";
			 }
			 }
		 }
private: System::Void buttonDec_Click(System::Object^  sender, System::EventArgs^  e) {
             pE[0] = &pse;
	         pE[1] = &se;
	         pE[2] = &qe;
			 openFileDialog1->InitialDirectory = "\\";
			 openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
			 openFileDialog1->FilterIndex = 2;
			 openFileDialog1->RestoreDirectory = true;

			 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				 if (openFileDialog1->OpenFile() != nullptr) {
					StreamReader^ input = gcnew StreamReader(openFileDialog1->FileName);
					String^ gcMessage = input->ReadLine();
					String^ gcKey = input->ReadLine();
					String^ gcIndex = input->ReadLine();

					input->Close();

					string codedMessage;
					int key;

					To_string(gcMessage, codedMessage);
					key = Convert::ToInt32(gcKey);
					index = Convert::ToInt32(gcIndex);

					if (index == 0)
						encodeType = "Prime Shift";
					else if (index == 1)
						encodeType = "Shifty";
					else
						encodeType = "Qwerty";

					pE[index]->SetCodedMessage(codedMessage, key);

					stringstream ssSummary;

					ssSummary << "Encoded Message: \"" << pE[index]->GetCodedMessage() << "\"" << endl;
					ssSummary << "Message: \"" << pE[index]->GetDecodedMessage() << "\"" << endl;
					ssSummary << "Key: " << key << endl;
					ssSummary << "Encryption: " << encodeType;
				 
					richTextBoxSummary->Text = gcnew String(ssSummary.str().c_str());
				 }
				 else
					 richTextBoxSummary->Text="File not opened!";
			 }
			 else {
				 richTextBoxSummary->Text="No file opened.";
			 }
		 }
private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ clear = "";

			 textBoxMessage->Text = clear;
			 richTextBoxSummary->Text = clear;
			 radioEnterKey->Checked = true;
			 NUDKey->Value = 1;

		 }
private: System::Void radioPrime_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 index = 0;
			 encodeType = "Prime Shift";
		 }
private: System::Void radioShifty_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 index = 1;
			 encodeType = "Shifty";
		 }
private: System::Void radioQwerty_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 index = 2;
			 encodeType = "Qwerty";
		 }
};
}

