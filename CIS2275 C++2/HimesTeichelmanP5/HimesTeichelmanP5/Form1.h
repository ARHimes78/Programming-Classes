// Alan Himes, Austin Teichelman
// arhimes1@cnm.edu, ateichelman@cnm.edu

#pragma once

/************************
Good job.  Hmmm. The form looks familiar.
When you display money, use $  -2
a llittle better summary at the end of the game - 
how many hands, how many losses, wins  -2
score 96/100
**********************/

#include <iostream>
#include <string>
#include <sstream>
#include "Game.h"
#include "UtilityFunctions.h"

using namespace System::Windows::Forms;//for the messagebox

namespace HimesTeichelmanP5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>

	Game game;

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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  MenuStripRules;
	private: System::Windows::Forms::Label^  labelWelcome1;
	private: System::Windows::Forms::Label^  labelWelcome2;
	private: System::Windows::Forms::Label^  labelWelcome3;
	private: System::Windows::Forms::Label^  labelEnterBet;
	private: System::Windows::Forms::Label^  labelPlayerHand;
	private: System::Windows::Forms::Label^  labelDealerHand;
	private: System::Windows::Forms::Label^  labelStatus;
	private: System::Windows::Forms::RichTextBox^  richTextBoxPlayer;
	private: System::Windows::Forms::RichTextBox^  richTextBoxDealer;
	private: System::Windows::Forms::Label^  labelHitOrStay;

	private: System::Windows::Forms::RichTextBox^  richTextBoxStatus;
	private: System::Windows::Forms::Button^  buttonHit;
	private: System::Windows::Forms::Button^  buttonStay;
	private: System::Windows::Forms::Button^  buttonPlayAgain;
	private: System::Windows::Forms::Button^  buttonQuit;
	private: System::Windows::Forms::Button^  buttonBet;
	private: System::Windows::Forms::TextBox^  textBoxBet;


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->MenuStripRules = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labelWelcome1 = (gcnew System::Windows::Forms::Label());
			this->labelWelcome2 = (gcnew System::Windows::Forms::Label());
			this->labelWelcome3 = (gcnew System::Windows::Forms::Label());
			this->labelEnterBet = (gcnew System::Windows::Forms::Label());
			this->labelPlayerHand = (gcnew System::Windows::Forms::Label());
			this->labelDealerHand = (gcnew System::Windows::Forms::Label());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->richTextBoxPlayer = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBoxDealer = (gcnew System::Windows::Forms::RichTextBox());
			this->labelHitOrStay = (gcnew System::Windows::Forms::Label());
			this->richTextBoxStatus = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonHit = (gcnew System::Windows::Forms::Button());
			this->buttonStay = (gcnew System::Windows::Forms::Button());
			this->buttonPlayAgain = (gcnew System::Windows::Forms::Button());
			this->buttonQuit = (gcnew System::Windows::Forms::Button());
			this->buttonBet = (gcnew System::Windows::Forms::Button());
			this->textBoxBet = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->MenuStripRules});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(770, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"RULES OF THE GAME";
			// 
			// MenuStripRules
			// 
			this->MenuStripRules->Name = L"MenuStripRules";
			this->MenuStripRules->Size = System::Drawing::Size(131, 20);
			this->MenuStripRules->Text = L"RULES OF THE GAME";
			this->MenuStripRules->Click += gcnew System::EventHandler(this, &Form1::MenuStripRulesItem_Click);
			// 
			// labelWelcome1
			// 
			this->labelWelcome1->AutoSize = true;
			this->labelWelcome1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelWelcome1->Location = System::Drawing::Point(233, 24);
			this->labelWelcome1->Name = L"labelWelcome1";
			this->labelWelcome1->Size = System::Drawing::Size(363, 27);
			this->labelWelcome1->TabIndex = 1;
			this->labelWelcome1->Text = L"Welcome to the C++ Blackjack Table!";
			// 
			// labelWelcome2
			// 
			this->labelWelcome2->AutoSize = true;
			this->labelWelcome2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelWelcome2->Location = System::Drawing::Point(122, 51);
			this->labelWelcome2->Name = L"labelWelcome2";
			this->labelWelcome2->Size = System::Drawing::Size(512, 27);
			this->labelWelcome2->TabIndex = 2;
			this->labelWelcome2->Text = L"You will begin with $1000 for your gambling pleasure.";
			// 
			// labelWelcome3
			// 
			this->labelWelcome3->AutoSize = true;
			this->labelWelcome3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelWelcome3->Location = System::Drawing::Point(73, 78);
			this->labelWelcome3->Name = L"labelWelcome3";
			this->labelWelcome3->Size = System::Drawing::Size(589, 27);
			this->labelWelcome3->TabIndex = 3;
			this->labelWelcome3->Text = L"You may view the rules by clicking on \"RULES OF THE GAME\"";
			// 
			// labelEnterBet
			// 
			this->labelEnterBet->AutoSize = true;
			this->labelEnterBet->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelEnterBet->Location = System::Drawing::Point(74, 126);
			this->labelEnterBet->Name = L"labelEnterBet";
			this->labelEnterBet->Size = System::Drawing::Size(385, 23);
			this->labelEnterBet->TabIndex = 4;
			this->labelEnterBet->Text = L"Enter your bet in the Box and press BET";
			// 
			// labelPlayerHand
			// 
			this->labelPlayerHand->AutoSize = true;
			this->labelPlayerHand->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelPlayerHand->Location = System::Drawing::Point(28, 187);
			this->labelPlayerHand->Name = L"labelPlayerHand";
			this->labelPlayerHand->Size = System::Drawing::Size(141, 27);
			this->labelPlayerHand->TabIndex = 5;
			this->labelPlayerHand->Text = L"Player\'s Hand";
			// 
			// labelDealerHand
			// 
			this->labelDealerHand->AutoSize = true;
			this->labelDealerHand->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelDealerHand->Location = System::Drawing::Point(28, 352);
			this->labelDealerHand->Name = L"labelDealerHand";
			this->labelDealerHand->Size = System::Drawing::Size(145, 27);
			this->labelDealerHand->TabIndex = 6;
			this->labelDealerHand->Text = L"Dealer\'s Hand";
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelStatus->Location = System::Drawing::Point(355, 366);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(131, 27);
			this->labelStatus->TabIndex = 7;
			this->labelStatus->Text = L"Game Status";
			// 
			// richTextBoxPlayer
			// 
			this->richTextBoxPlayer->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 14.25F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->richTextBoxPlayer->Location = System::Drawing::Point(33, 217);
			this->richTextBoxPlayer->Name = L"richTextBoxPlayer";
			this->richTextBoxPlayer->ReadOnly = true;
			this->richTextBoxPlayer->Size = System::Drawing::Size(218, 124);
			this->richTextBoxPlayer->TabIndex = 8;
			this->richTextBoxPlayer->Text = L"";
			// 
			// richTextBoxDealer
			// 
			this->richTextBoxDealer->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 14.25F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->richTextBoxDealer->Location = System::Drawing::Point(33, 382);
			this->richTextBoxDealer->Name = L"richTextBoxDealer";
			this->richTextBoxDealer->ReadOnly = true;
			this->richTextBoxDealer->Size = System::Drawing::Size(218, 124);
			this->richTextBoxDealer->TabIndex = 9;
			this->richTextBoxDealer->Text = L"";
			// 
			// labelHitOrStay
			// 
			this->labelHitOrStay->AutoSize = true;
			this->labelHitOrStay->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelHitOrStay->Location = System::Drawing::Point(324, 217);
			this->labelHitOrStay->Name = L"labelHitOrStay";
			this->labelHitOrStay->Size = System::Drawing::Size(297, 23);
			this->labelHitOrStay->TabIndex = 10;
			this->labelHitOrStay->Text = L"Press the Hit or Stay button =>";
			this->labelHitOrStay->Visible = false;
			// 
			// richTextBoxStatus
			// 
			this->richTextBoxStatus->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 14.25F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->richTextBoxStatus->Location = System::Drawing::Point(360, 407);
			this->richTextBoxStatus->Name = L"richTextBoxStatus";
			this->richTextBoxStatus->ReadOnly = true;
			this->richTextBoxStatus->Size = System::Drawing::Size(322, 124);
			this->richTextBoxStatus->TabIndex = 11;
			this->richTextBoxStatus->Text = L"";
			// 
			// buttonHit
			// 
			this->buttonHit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonHit->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonHit->Location = System::Drawing::Point(636, 176);
			this->buttonHit->Name = L"buttonHit";
			this->buttonHit->Size = System::Drawing::Size(88, 47);
			this->buttonHit->TabIndex = 12;
			this->buttonHit->Text = L"HIT";
			this->buttonHit->UseVisualStyleBackColor = false;
			this->buttonHit->Visible = false;
			this->buttonHit->Click += gcnew System::EventHandler(this, &Form1::buttonHit_Click);
			// 
			// buttonStay
			// 
			this->buttonStay->BackColor = System::Drawing::Color::Red;
			this->buttonStay->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonStay->Location = System::Drawing::Point(636, 231);
			this->buttonStay->Name = L"buttonStay";
			this->buttonStay->Size = System::Drawing::Size(88, 47);
			this->buttonStay->TabIndex = 13;
			this->buttonStay->Text = L"STAY";
			this->buttonStay->UseVisualStyleBackColor = false;
			this->buttonStay->Visible = false;
			this->buttonStay->Click += gcnew System::EventHandler(this, &Form1::buttonStay_Click);
			// 
			// buttonPlayAgain
			// 
			this->buttonPlayAgain->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonPlayAgain->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonPlayAgain->Location = System::Drawing::Point(341, 257);
			this->buttonPlayAgain->Name = L"buttonPlayAgain";
			this->buttonPlayAgain->Size = System::Drawing::Size(199, 84);
			this->buttonPlayAgain->TabIndex = 14;
			this->buttonPlayAgain->Text = L"PLAY AGAIN!";
			this->buttonPlayAgain->UseVisualStyleBackColor = false;
			this->buttonPlayAgain->Click += gcnew System::EventHandler(this, &Form1::buttonPlayAgain_Click);
			// 
			// buttonQuit
			// 
			this->buttonQuit->BackColor = System::Drawing::Color::Black;
			this->buttonQuit->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonQuit->ForeColor = System::Drawing::Color::White;
			this->buttonQuit->Location = System::Drawing::Point(594, 317);
			this->buttonQuit->Name = L"buttonQuit";
			this->buttonQuit->Size = System::Drawing::Size(130, 62);
			this->buttonQuit->TabIndex = 15;
			this->buttonQuit->Text = L"I QUIT!";
			this->buttonQuit->UseVisualStyleBackColor = false;
			this->buttonQuit->Click += gcnew System::EventHandler(this, &Form1::buttonQuit_Click);
			// 
			// buttonBet
			// 
			this->buttonBet->BackColor = System::Drawing::Color::Purple;
			this->buttonBet->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonBet->ForeColor = System::Drawing::Color::White;
			this->buttonBet->Location = System::Drawing::Point(636, 121);
			this->buttonBet->Name = L"buttonBet";
			this->buttonBet->Size = System::Drawing::Size(88, 47);
			this->buttonBet->TabIndex = 16;
			this->buttonBet->Text = L"BET";
			this->buttonBet->UseVisualStyleBackColor = false;
			this->buttonBet->Click += gcnew System::EventHandler(this, &Form1::buttonBet_Click);
			// 
			// textBoxBet
			// 
			this->textBoxBet->Location = System::Drawing::Point(492, 128);
			this->textBoxBet->Name = L"textBoxBet";
			this->textBoxBet->Size = System::Drawing::Size(100, 20);
			this->textBoxBet->TabIndex = 17;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(770, 560);
			this->Controls->Add(this->textBoxBet);
			this->Controls->Add(this->buttonBet);
			this->Controls->Add(this->buttonQuit);
			this->Controls->Add(this->buttonPlayAgain);
			this->Controls->Add(this->buttonStay);
			this->Controls->Add(this->buttonHit);
			this->Controls->Add(this->richTextBoxStatus);
			this->Controls->Add(this->labelHitOrStay);
			this->Controls->Add(this->richTextBoxDealer);
			this->Controls->Add(this->richTextBoxPlayer);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->labelDealerHand);
			this->Controls->Add(this->labelPlayerHand);
			this->Controls->Add(this->labelEnterBet);
			this->Controls->Add(this->labelWelcome3);
			this->Controls->Add(this->labelWelcome2);
			this->Controls->Add(this->labelWelcome1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Alan Himes/Austin Teichelman - Blackjack";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MenuStripRulesItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 stringstream ssRules;

				 //copies the rules from the blackjackexample verbatim
				 ssRules << "You may place a bet between $1 and however much money you have.\n";
				 ssRules << "Then, you will have two cards dealt to you, as will the dealer.\n";
				 ssRules << "One of the dealer's cards will be hidden.\n";
				 ssRules << "The object of the game is to get as close to 21 as you can,\n";
				 ssRules << "without going over. Whoever gets the closest without going over wins.\n";
				 ssRules << "If you go over 21, you are busted and lose.\n";
				 ssRules << "If you hit 21 exactly, you get Blackjack and win automatically.\n";
				 ssRules << "You may HIT (ask for another card) or Stay (play the cards you have)\n";
				 ssRules << "The dealer is required to hit on 16 or less.";

				 string normalStringRules = ssRules.str();
				 String^ rules = gcnew String(normalStringRules.c_str());
				 MessageBox::Show(rules);

				 //richTextBoxSummary->Text = gcnew String(ticket.GetReservationDescription().c_str());
			 }
	private: System::Void buttonBet_Click(System::Object^  sender, System::EventArgs^  e) {
				 game.SetInProgress(true);//This is set to false if the game is over.

				 if (textBoxBet->Text != "") {
					/*Taking amount bet from the textbox, converting it to a normal string,
					then converting the string to an int to be passed into a Game class object method.
					*/
					String^ betAmountFromTextBox = textBoxBet->Text;
					string sBetAmount;
					To_string(betAmountFromTextBox, sBetAmount);//from UtilityFunctions.h
					double betAmount = atoi(sBetAmount.c_str());
				 				 
					game.SetStay(false);

					if (!game.SetBet(betAmount))
						cout << "Invalid bet amount!" << endl;
					else {
						game.InitialDeal();
						
						richTextBoxPlayer->Text = gcnew String(game.ShowPlayerHand().c_str());
						richTextBoxDealer->Text = gcnew String(game.ShowDealersHand(true).c_str());
						richTextBoxStatus->Text = gcnew String(game.ShowResults().c_str());
    
					}

					labelHitOrStay->Visible = true;
					buttonHit->Visible = true;
					buttonStay->Visible = true;
					labelEnterBet->Visible = false;
					buttonBet->Visible = false;
					textBoxBet->Visible = false;

				}

				 //if the player immediately receives a blackjack hand, hit and stay buttons are disbled.
				 if (game.IsBlackJack()) {
					 buttonHit->Enabled = false;
					buttonStay->Enabled = false;
				 }

			 }
private: System::Void buttonPlayAgain_Click(System::Object^  sender, System::EventArgs^  e) {
				game.ClearHands();
				
				labelHitOrStay->Visible = false;
				buttonHit->Visible = false;
				buttonStay->Visible = false;
				labelEnterBet->Visible = true;
				buttonBet->Visible = true;
				textBoxBet->Visible = true;

				String^ blank = "";
				textBoxBet->Text = blank;
				richTextBoxPlayer->Text = blank;
				richTextBoxDealer->Text = blank;
				richTextBoxStatus->Text = blank;

				buttonHit->Enabled = true;
				buttonStay->Enabled = true;
		 }
private: System::Void buttonHit_Click(System::Object^  sender, System::EventArgs^  e) {

			 game.SetStay(false);
    
			if (game.PlayerContinues()) {
				game.PlayerHits();
				richTextBoxPlayer->Text = gcnew String(game.ShowPlayerHand().c_str());
				
				if (game.DealerContinues())
					richTextBoxDealer->Text = gcnew String(game.ShowDealersHand(true).c_str());
			}
			
			richTextBoxStatus->Text = gcnew String(game.ShowResults().c_str());

			if (!game.IsInProgress()) {//game over
				richTextBoxDealer->Text = gcnew String(game.ShowDealersHand(false).c_str());
				buttonHit->Enabled = false;
				buttonStay->Enabled = false;
			}
		 }
		 
private: System::Void buttonStay_Click(System::Object^  sender, System::EventArgs^  e) {
		
			game.SetStay(true);

			//with the do loop, the dealer will keep dealing until it busts/wins/ties.
			do {
				if (game.DealerContinues()) {
					richTextBoxPlayer->Text = gcnew String(game.ShowPlayerHand().c_str());
					richTextBoxDealer->Text = gcnew String(game.ShowDealersHand(true).c_str());
				}
			}while (game.GetDealerHit());


    
			richTextBoxStatus->Text = gcnew String(game.ShowResults().c_str());

			if (!game.IsInProgress()) {//game over
				richTextBoxDealer->Text = gcnew String(game.ShowDealersHand(false).c_str());
				buttonHit->Enabled = false;
				buttonStay->Enabled = false;
			}
		 }
private: System::Void buttonQuit_Click(System::Object^  sender, System::EventArgs^  e) {
			 game.EndGame();
			 exit(1);
		 }
};
}

