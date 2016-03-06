#pragma once
#include <string>
#include "Date.h"
#include "CPPTrainTickets.h"
#include "UtilityFunctions.h"

/**********************
score 95/100
***********************/

namespace HimesP6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>


	Date booking;
	string city = "Albuquerque";
	

	public ref class Form1 : public System::Windows::Forms::Form
	{

		void roundTrip(bool check){
			labelReturn->Visible = check;
			labelReturnMonth->Visible = check;
			labelReturnDay->Visible = check;
			labelReturnYear->Visible = check;
			NUDRetMonth->Visible = check;
			NUDRetDay->Visible = check;
			NUDRetYear->Visible = check;
		}

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

	
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  labelReturn;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  labelReturnMonth;
	private: System::Windows::Forms::Label^  labelReturnDay;
	private: System::Windows::Forms::Label^  labelReturnYear;



	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::RichTextBox^  richTextBoxSummary;

	private: System::Windows::Forms::Button^  buttonReservation;
	private: System::Windows::Forms::TextBox^  textBoxResName;


	private: System::Windows::Forms::CheckBox^  checkBoxRoundTrip;
	private: System::Windows::Forms::Button^  buttonAnotherRes;
	private: System::Windows::Forms::NumericUpDown^  NUDDepMonth;
	private: System::Windows::Forms::NumericUpDown^  NUDDepDay;
	private: System::Windows::Forms::NumericUpDown^  NUDDepYear;
	private: System::Windows::Forms::NumericUpDown^  NUDRetMonth;
	private: System::Windows::Forms::NumericUpDown^  NUDRetDay;
	private: System::Windows::Forms::NumericUpDown^  NUDRetYear;
	private: System::Windows::Forms::NumericUpDown^  NUDNumPass;
	private: System::Windows::Forms::RadioButton^  radioButtonChicago;
	private: System::Windows::Forms::RadioButton^  radioButtonAbq;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelReturn = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->labelReturnMonth = (gcnew System::Windows::Forms::Label());
			this->labelReturnDay = (gcnew System::Windows::Forms::Label());
			this->labelReturnYear = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->richTextBoxSummary = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonReservation = (gcnew System::Windows::Forms::Button());
			this->textBoxResName = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxRoundTrip = (gcnew System::Windows::Forms::CheckBox());
			this->buttonAnotherRes = (gcnew System::Windows::Forms::Button());
			this->NUDDepMonth = (gcnew System::Windows::Forms::NumericUpDown());
			this->NUDDepDay = (gcnew System::Windows::Forms::NumericUpDown());
			this->NUDDepYear = (gcnew System::Windows::Forms::NumericUpDown());
			this->NUDRetMonth = (gcnew System::Windows::Forms::NumericUpDown());
			this->NUDRetDay = (gcnew System::Windows::Forms::NumericUpDown());
			this->NUDRetYear = (gcnew System::Windows::Forms::NumericUpDown());
			this->NUDNumPass = (gcnew System::Windows::Forms::NumericUpDown());
			this->radioButtonChicago = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonAbq = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDDepMonth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDDepDay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDDepYear))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDRetMonth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDRetDay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDRetYear))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDNumPass))->BeginInit();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::Window;
			this->richTextBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(1176, 220);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 268);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(227, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Enter name on reservation:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(501, 369);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Check for round trip";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(878, 279);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(214, 25);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Select date for departure:";
			// 
			// labelReturn
			// 
			this->labelReturn->AutoSize = true;
			this->labelReturn->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelReturn->Location = System::Drawing::Point(878, 416);
			this->labelReturn->Name = L"labelReturn";
			this->labelReturn->Size = System::Drawing::Size(184, 25);
			this->labelReturn->TabIndex = 4;
			this->labelReturn->Text = L"Select date for return:";
			this->labelReturn->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(883, 304);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 25);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Month";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(961, 304);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(43, 25);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Day";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(1029, 304);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 25);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Year";
			// 
			// labelReturnMonth
			// 
			this->labelReturnMonth->AutoSize = true;
			this->labelReturnMonth->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelReturnMonth->Location = System::Drawing::Point(883, 441);
			this->labelReturnMonth->Name = L"labelReturnMonth";
			this->labelReturnMonth->Size = System::Drawing::Size(62, 25);
			this->labelReturnMonth->TabIndex = 9;
			this->labelReturnMonth->Text = L"Month";
			this->labelReturnMonth->Visible = false;
			// 
			// labelReturnDay
			// 
			this->labelReturnDay->AutoSize = true;
			this->labelReturnDay->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelReturnDay->Location = System::Drawing::Point(961, 441);
			this->labelReturnDay->Name = L"labelReturnDay";
			this->labelReturnDay->Size = System::Drawing::Size(43, 25);
			this->labelReturnDay->TabIndex = 10;
			this->labelReturnDay->Text = L"Day";
			this->labelReturnDay->Visible = false;
			// 
			// labelReturnYear
			// 
			this->labelReturnYear->AutoSize = true;
			this->labelReturnYear->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelReturnYear->Location = System::Drawing::Point(1029, 441);
			this->labelReturnYear->Name = L"labelReturnYear";
			this->labelReturnYear->Size = System::Drawing::Size(50, 25);
			this->labelReturnYear->TabIndex = 11;
			this->labelReturnYear->Text = L"Year";
			this->labelReturnYear->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(17, 405);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(240, 25);
			this->label4->TabIndex = 12;
			this->label4->Text = L"How many are in your party\?";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(17, 493);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(149, 25);
			this->label8->TabIndex = 13;
			this->label8->Text = L"City of departure:";
			// 
			// richTextBoxSummary
			// 
			this->richTextBoxSummary->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->richTextBoxSummary->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBoxSummary->ForeColor = System::Drawing::SystemColors::Window;
			this->richTextBoxSummary->Location = System::Drawing::Point(98, 600);
			this->richTextBoxSummary->Name = L"richTextBoxSummary";
			this->richTextBoxSummary->ReadOnly = true;
			this->richTextBoxSummary->Size = System::Drawing::Size(527, 188);
			this->richTextBoxSummary->TabIndex = 14;
			this->richTextBoxSummary->Text = L"";
			// 
			// buttonReservation
			// 
			this->buttonReservation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->buttonReservation->Font = (gcnew System::Drawing::Font(L"Cooper Black", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonReservation->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonReservation->Location = System::Drawing::Point(448, 458);
			this->buttonReservation->Name = L"buttonReservation";
			this->buttonReservation->Size = System::Drawing::Size(247, 122);
			this->buttonReservation->TabIndex = 15;
			this->buttonReservation->Text = L"Make my reservation\r\n";
			this->buttonReservation->UseVisualStyleBackColor = false;
			this->buttonReservation->Click += gcnew System::EventHandler(this, &Form1::buttonReservation_Click);
			// 
			// textBoxResName
			// 
			this->textBoxResName->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBoxResName->Location = System::Drawing::Point(17, 304);
			this->textBoxResName->Name = L"textBoxResName";
			this->textBoxResName->Size = System::Drawing::Size(222, 32);
			this->textBoxResName->TabIndex = 16;
			// 
			// checkBoxRoundTrip
			// 
			this->checkBoxRoundTrip->AutoSize = true;
			this->checkBoxRoundTrip->Location = System::Drawing::Point(480, 378);
			this->checkBoxRoundTrip->Name = L"checkBoxRoundTrip";
			this->checkBoxRoundTrip->Size = System::Drawing::Size(15, 14);
			this->checkBoxRoundTrip->TabIndex = 18;
			this->checkBoxRoundTrip->UseVisualStyleBackColor = true;
			this->checkBoxRoundTrip->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxRoundTrip_CheckedChanged);
			// 
			// buttonAnotherRes
			// 
			this->buttonAnotherRes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->buttonAnotherRes->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonAnotherRes->ForeColor = System::Drawing::SystemColors::Window;
			this->buttonAnotherRes->Location = System::Drawing::Point(902, 627);
			this->buttonAnotherRes->Name = L"buttonAnotherRes";
			this->buttonAnotherRes->Size = System::Drawing::Size(223, 110);
			this->buttonAnotherRes->TabIndex = 19;
			this->buttonAnotherRes->Text = L"Make another reservation";
			this->buttonAnotherRes->UseVisualStyleBackColor = false;
			this->buttonAnotherRes->Click += gcnew System::EventHandler(this, &Form1::buttonAnotherRes_Click);
			// 
			// NUDDepMonth
			// 
			this->NUDDepMonth->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NUDDepMonth->Location = System::Drawing::Point(888, 332);
			this->NUDDepMonth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {12, 0, 0, 0});
			this->NUDDepMonth->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NUDDepMonth->Name = L"NUDDepMonth";
			this->NUDDepMonth->Size = System::Drawing::Size(44, 32);
			this->NUDDepMonth->TabIndex = 20;
			this->NUDDepMonth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// NUDDepDay
			// 
			this->NUDDepDay->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NUDDepDay->Location = System::Drawing::Point(966, 332);
			this->NUDDepDay->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {31, 0, 0, 0});
			this->NUDDepDay->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NUDDepDay->Name = L"NUDDepDay";
			this->NUDDepDay->Size = System::Drawing::Size(46, 32);
			this->NUDDepDay->TabIndex = 21;
			this->NUDDepDay->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// NUDDepYear
			// 
			this->NUDDepYear->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NUDDepYear->Location = System::Drawing::Point(1034, 332);
			this->NUDDepYear->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2015, 0, 0, 0});
			this->NUDDepYear->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2014, 0, 0, 0});
			this->NUDDepYear->Name = L"NUDDepYear";
			this->NUDDepYear->Size = System::Drawing::Size(74, 32);
			this->NUDDepYear->TabIndex = 22;
			this->NUDDepYear->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2014, 0, 0, 0});
			// 
			// NUDRetMonth
			// 
			this->NUDRetMonth->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NUDRetMonth->Location = System::Drawing::Point(888, 469);
			this->NUDRetMonth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {12, 0, 0, 0});
			this->NUDRetMonth->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NUDRetMonth->Name = L"NUDRetMonth";
			this->NUDRetMonth->Size = System::Drawing::Size(44, 32);
			this->NUDRetMonth->TabIndex = 23;
			this->NUDRetMonth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NUDRetMonth->Visible = false;
			// 
			// NUDRetDay
			// 
			this->NUDRetDay->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NUDRetDay->Location = System::Drawing::Point(966, 469);
			this->NUDRetDay->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {31, 0, 0, 0});
			this->NUDRetDay->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NUDRetDay->Name = L"NUDRetDay";
			this->NUDRetDay->Size = System::Drawing::Size(46, 32);
			this->NUDRetDay->TabIndex = 24;
			this->NUDRetDay->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NUDRetDay->Visible = false;
			// 
			// NUDRetYear
			// 
			this->NUDRetYear->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NUDRetYear->Location = System::Drawing::Point(1034, 469);
			this->NUDRetYear->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2015, 0, 0, 0});
			this->NUDRetYear->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2014, 0, 0, 0});
			this->NUDRetYear->Name = L"NUDRetYear";
			this->NUDRetYear->Size = System::Drawing::Size(74, 32);
			this->NUDRetYear->TabIndex = 25;
			this->NUDRetYear->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2014, 0, 0, 0});
			this->NUDRetYear->Visible = false;
			// 
			// NUDNumPass
			// 
			this->NUDNumPass->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NUDNumPass->Location = System::Drawing::Point(274, 405);
			this->NUDNumPass->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->NUDNumPass->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NUDNumPass->Name = L"NUDNumPass";
			this->NUDNumPass->Size = System::Drawing::Size(44, 32);
			this->NUDNumPass->TabIndex = 26;
			this->NUDNumPass->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// radioButtonChicago
			// 
			this->radioButtonChicago->AutoSize = true;
			this->radioButtonChicago->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButtonChicago->Location = System::Drawing::Point(22, 521);
			this->radioButtonChicago->Name = L"radioButtonChicago";
			this->radioButtonChicago->Size = System::Drawing::Size(95, 29);
			this->radioButtonChicago->TabIndex = 27;
			this->radioButtonChicago->TabStop = true;
			this->radioButtonChicago->Text = L"Chicago";
			this->radioButtonChicago->UseVisualStyleBackColor = true;
			this->radioButtonChicago->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButtonChicago_CheckedChanged);
			// 
			// radioButtonAbq
			// 
			this->radioButtonAbq->AutoSize = true;
			this->radioButtonAbq->Checked = true;
			this->radioButtonAbq->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButtonAbq->Location = System::Drawing::Point(123, 521);
			this->radioButtonAbq->Name = L"radioButtonAbq";
			this->radioButtonAbq->Size = System::Drawing::Size(131, 29);
			this->radioButtonAbq->TabIndex = 28;
			this->radioButtonAbq->TabStop = true;
			this->radioButtonAbq->Text = L"Albuquerque";
			this->radioButtonAbq->UseVisualStyleBackColor = true;
			this->radioButtonAbq->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButtonAbq_CheckedChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(1200, 800);
			this->Controls->Add(this->radioButtonAbq);
			this->Controls->Add(this->radioButtonChicago);
			this->Controls->Add(this->NUDNumPass);
			this->Controls->Add(this->NUDRetYear);
			this->Controls->Add(this->NUDRetDay);
			this->Controls->Add(this->NUDRetMonth);
			this->Controls->Add(this->NUDDepYear);
			this->Controls->Add(this->NUDDepDay);
			this->Controls->Add(this->NUDDepMonth);
			this->Controls->Add(this->buttonAnotherRes);
			this->Controls->Add(this->checkBoxRoundTrip);
			this->Controls->Add(this->textBoxResName);
			this->Controls->Add(this->buttonReservation);
			this->Controls->Add(this->richTextBoxSummary);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->labelReturnYear);
			this->Controls->Add(this->labelReturnDay);
			this->Controls->Add(this->labelReturnMonth);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->labelReturn);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"Form1";
			this->Text = L"Program 4/6 C++ Express Train tickets with overloaded operators - Alan Himes";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDDepMonth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDDepDay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDDepYear))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDRetMonth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDRetDay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDRetYear))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NUDNumPass))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	

	private: System::Void buttonReservation_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ resNameFromTextBox = textBoxResName->Text;
				 string resName; 
				 To_string(resNameFromTextBox, resName);//from UtilityFunctions.h
				 int numPass = Decimal::ToInt32(NUDNumPass->Value);
				 int depMonth = Decimal::ToInt32(NUDDepMonth->Value);
				 int depDay = Decimal::ToInt32(NUDDepDay->Value);
				 int depYear = Decimal::ToInt32(NUDDepYear->Value);
				 Date departure(depMonth, depDay, depYear, "Departure");
				 
				 if (checkBoxRoundTrip->Checked) {
					int retMonth = Decimal::ToInt32(NUDRetMonth->Value);
					int retDay = Decimal::ToInt32(NUDRetDay->Value);
					int retYear = Decimal::ToInt32(NUDRetYear->Value);
					Date returnTrip(retMonth, retDay, retYear, "Return");

					CPPTrainTickets ticket(resName, numPass, booking, departure, returnTrip);
					ticket.SetDepartingCity(city);
					richTextBoxSummary->Text = gcnew String(ticket.GetReservationDescription().c_str());
				 }
				 else {
					CPPTrainTickets ticket(resName, numPass, booking, departure);
					ticket.SetDepartingCity(city);
					richTextBoxSummary->Text = gcnew String(ticket.GetReservationDescription().c_str());
				 }

				 

			 }
private: System::Void checkBoxRoundTrip_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (checkBoxRoundTrip->Checked) {
				 roundTrip(true);
			 }
			 else {
				 roundTrip(false);
			 }
		 }

private: System::Void buttonAnotherRes_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBoxResName->Clear();
			 richTextBoxSummary->Clear();
			 checkBoxRoundTrip->Checked = false;
			 NUDNumPass->Value = 1;
			 NUDDepMonth->Value = 1;
			 NUDDepDay->Value = 1;
			 NUDDepYear->Value = 2014;
			 NUDRetMonth->Value = 1;
			 NUDRetDay->Value = 1;
			 NUDRetYear->Value = 2014;
			 radioButtonAbq->Checked = true;
		 }
private: System::Void radioButtonChicago_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButtonChicago->Checked)
				 city = "Chicago";
		 }
private: System::Void radioButtonAbq_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButtonAbq->Checked)
				 city = "Albuquerque";
		 }
};
}

