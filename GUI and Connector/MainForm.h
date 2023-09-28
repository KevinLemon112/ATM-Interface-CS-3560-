#pragma once

#include "Form2.h"
namespace TestGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		String^ email;
		String^ cID;
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbCardNum;
	protected:

	private: System::Windows::Forms::TextBox^ tbCardNum;
	protected:


	protected:

	protected:


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnClear;


	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::Label^ lbDisplay;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::TextBox^ tbPinNum;

	private: System::Windows::Forms::Label^ lbPinNum;





	private: System::Windows::Forms::Label^ lbWelcome;


	private: System::ComponentModel::IContainer^ components;



	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lbCardNum = (gcnew System::Windows::Forms::Label());
			this->tbCardNum = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->lbDisplay = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tbPinNum = (gcnew System::Windows::Forms::TextBox());
			this->lbPinNum = (gcnew System::Windows::Forms::Label());
			this->lbWelcome = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbCardNum
			// 
			this->lbCardNum->AutoSize = true;
			this->lbCardNum->BackColor = System::Drawing::Color::Transparent;
			this->lbCardNum->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCardNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->lbCardNum->Location = System::Drawing::Point(36, 134);
			this->lbCardNum->Name = L"lbCardNum";
			this->lbCardNum->Size = System::Drawing::Size(195, 23);
			this->lbCardNum->TabIndex = 0;
			this->lbCardNum->Text = L"16 Digit Card Number";
			// 
			// tbCardNum
			// 
			this->tbCardNum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbCardNum->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tbCardNum->Location = System::Drawing::Point(37, 160);
			this->tbCardNum->MaxLength = 16;
			this->tbCardNum->Name = L"tbCardNum";
			this->tbCardNum->Size = System::Drawing::Size(607, 22);
			this->tbCardNum->TabIndex = 1;
			this->tbCardNum->TextChanged += gcnew System::EventHandler(this, &MainForm::tbCardNum_TextChanged);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->btnClear, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnSubmit, 0, 0);
			this->tableLayoutPanel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(37, 291);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(607, 64);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// btnClear
			// 
			this->btnClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnClear->Location = System::Drawing::Point(306, 3);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(298, 58);
			this->btnClear->TabIndex = 4;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &MainForm::btnClear_Click);
			// 
			// btnSubmit
			// 
			this->btnSubmit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSubmit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubmit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnSubmit->Location = System::Drawing::Point(3, 3);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(297, 58);
			this->btnSubmit->TabIndex = 3;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = false;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// lbDisplay
			// 
			this->lbDisplay->AutoSize = true;
			this->lbDisplay->Location = System::Drawing::Point(41, 441);
			this->lbDisplay->Name = L"lbDisplay";
			this->lbDisplay->Size = System::Drawing::Size(0, 17);
			this->lbDisplay->TabIndex = 3;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// tbPinNum
			// 
			this->tbPinNum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbPinNum->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tbPinNum->Location = System::Drawing::Point(37, 230);
			this->tbPinNum->MaxLength = 4;
			this->tbPinNum->Name = L"tbPinNum";
			this->tbPinNum->PasswordChar = '*';
			this->tbPinNum->Size = System::Drawing::Size(607, 22);
			this->tbPinNum->TabIndex = 6;
			// 
			// lbPinNum
			// 
			this->lbPinNum->AutoSize = true;
			this->lbPinNum->BackColor = System::Drawing::Color::Transparent;
			this->lbPinNum->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPinNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->lbPinNum->Location = System::Drawing::Point(36, 204);
			this->lbPinNum->Name = L"lbPinNum";
			this->lbPinNum->Size = System::Drawing::Size(170, 23);
			this->lbPinNum->TabIndex = 7;
			this->lbPinNum->Text = L"4 Digit Pin Number";
			// 
			// lbWelcome
			// 
			this->lbWelcome->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbWelcome->AutoSize = true;
			this->lbWelcome->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbWelcome->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbWelcome->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->lbWelcome->Location = System::Drawing::Point(30, 48);
			this->lbWelcome->Name = L"lbWelcome";
			this->lbWelcome->Size = System::Drawing::Size(628, 38);
			this->lbWelcome->TabIndex = 9;
			this->lbWelcome->Text = L"Welcome To The Purloin Bank ATM System ";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(214)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->ClientSize = System::Drawing::Size(821, 435);
			this->Controls->Add(this->lbWelcome);
			this->Controls->Add(this->lbPinNum);
			this->Controls->Add(this->tbPinNum);
			this->Controls->Add(this->lbDisplay);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbCardNum);
			this->Controls->Add(this->lbCardNum);
			this->MaximumSize = System::Drawing::Size(839, 482);
			this->MinimumSize = System::Drawing::Size(839, 482);
			this->Name = L"MainForm";
			this->Text = L"ATM Login";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Submits user inputs to database and checks if their inputed email and id exist
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//Takes in user inputs and stores them in variables
		String^ cardNum = this->tbCardNum->Text;
		String^ pinNum = this->tbPinNum->Text;
		String^ cID;
		

		//Connect to MySql data base and to check if a user with the email and id inputted into text box exist
		String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
		MySqlConnection^ conDatabaseGetCID = gcnew MySqlConnection(consting);
		/*MySqlCommand^ cmDataBase = gcnew MySqlCommand("select * from atm_system.customer where customerID ='" + this->tbPinNum->Text + "' and email='" + this->tbCardNum->Text + "';", conDatabase);
		MySqlDataReader^ myReader;*/
		MySqlCommand^ cmDataBase = gcnew MySqlCommand("select * from atm_system.atmcard where pinNo ='" + this->tbPinNum->Text + "' and cardNo='" + this->tbCardNum->Text + "';", conDatabase);
		MySqlDataReader^ myReader;
		MySqlCommand^ cmDataBaseGetCID = gcnew MySqlCommand("select * from atm_system.accounts where cardNo='" + this->tbCardNum->Text + "';", conDatabaseGetCID);
		MySqlDataReader^ myReaderGetCID;

		try
		{
			//Execute query
			conDatabase->Open();
			myReader = cmDataBase->ExecuteReader();

			//Checks if duplicate your inputed email and Id belong to multiple users
			int count = 0;
			while (myReader->Read())
			{
				count += 1;
			}
			if (count == 1)
			{
				MessageBox::Show("Card Number and and Pin are correct");
				
				//Get customer ID
				conDatabaseGetCID->Open();
				myReaderGetCID = cmDataBaseGetCID->ExecuteReader();
				if (myReaderGetCID->Read())
				{
					cID = myReaderGetCID->GetInt32("customerID").ToString();
				}
				//Opens next form after hiding current one
				this->Hide();
				this->tbCardNum->Text = "";
				this->tbPinNum->Text = "";
				//Sends a handle of the customer to the next form in order to perform future queries
				Form2^ f2 = gcnew Form2(this, cID);
				f2->ShowDialog();
			}
			else if (count > 1)
			{
				MessageBox::Show("There are Duplicate Emails and IDs ...Access Denied");
			}
			else
			{
				MessageBox::Show("Email and/or ID Incorrect ...Please Try Again");
			}
			
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}
	//Sets text in text boxes to blank
	private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
		this->tbCardNum->Text = "";
		this->tbPinNum->Text = "";
	}

private: System::Void tbCardNum_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
