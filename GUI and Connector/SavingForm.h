#pragma once
#include "DepositForm.h"
#include "TransferForm.h"
#include "CheckBalanceForm.h"
#include "TransactionHistoryForm1.h";


namespace TestGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SavingForm
	/// </summary>
	public ref class SavingForm : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		Form^ prev;
	private: System::Windows::Forms::Button^ btnTransactionHistory;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	public:

	public:
		String^ cID;
		SavingForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		SavingForm(Form^ _obj, String^ _cID)
		{
			obj = _obj;
			cID = _cID;
			InitializeComponent();
		}
		SavingForm(Form^ _obj, Form^ _prev, String^ _cID)
		{
			obj = _obj;
			prev = _prev;
			cID = _cID;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SavingForm()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:


	private: System::Windows::Forms::Button^ btnLogout;
	private: System::Windows::Forms::Button^ btnPrev;
	private: System::Windows::Forms::Label^ lbTransactionType;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnCheckBalance;
	private: System::Windows::Forms::Button^ btnDeposit;
	private: System::Windows::Forms::Button^ btnTransfer;


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
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnPrev = (gcnew System::Windows::Forms::Button());
			this->lbTransactionType = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnTransactionHistory = (gcnew System::Windows::Forms::Button());
			this->btnCheckBalance = (gcnew System::Windows::Forms::Button());
			this->btnDeposit = (gcnew System::Windows::Forms::Button());
			this->btnTransfer = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnLogout->BackColor = System::Drawing::Color::MistyRose;
			this->btnLogout->Location = System::Drawing::Point(1020, 21);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(108, 32);
			this->btnLogout->TabIndex = 10;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &SavingForm::btnLogout_Click);
			// 
			// btnPrev
			// 
			this->btnPrev->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnPrev->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnPrev->Location = System::Drawing::Point(3, 3);
			this->btnPrev->Name = L"btnPrev";
			this->btnPrev->Size = System::Drawing::Size(158, 37);
			this->btnPrev->TabIndex = 11;
			this->btnPrev->Text = L"Prev";
			this->btnPrev->UseVisualStyleBackColor = false;
			this->btnPrev->Click += gcnew System::EventHandler(this, &SavingForm::btnPrev_Click);
			// 
			// lbTransactionType
			// 
			this->lbTransactionType->AutoSize = true;
			this->lbTransactionType->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTransactionType->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->lbTransactionType->Location = System::Drawing::Point(12, 24);
			this->lbTransactionType->Name = L"lbTransactionType";
			this->lbTransactionType->Size = System::Drawing::Size(206, 23);
			this->lbTransactionType->TabIndex = 12;
			this->lbTransactionType->Text = L"Please Select an Action";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->btnTransactionHistory, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnCheckBalance, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnDeposit, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnTransfer, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(16, 98);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1112, 198);
			this->tableLayoutPanel1->TabIndex = 13;
			// 
			// btnTransactionHistory
			// 
			this->btnTransactionHistory->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnTransactionHistory->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTransactionHistory->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnTransactionHistory->Location = System::Drawing::Point(837, 3);
			this->btnTransactionHistory->Name = L"btnTransactionHistory";
			this->btnTransactionHistory->Size = System::Drawing::Size(272, 192);
			this->btnTransactionHistory->TabIndex = 14;
			this->btnTransactionHistory->Text = L"Transaction History";
			this->btnTransactionHistory->UseVisualStyleBackColor = false;
			this->btnTransactionHistory->Click += gcnew System::EventHandler(this, &SavingForm::button1_Click);
			// 
			// btnCheckBalance
			// 
			this->btnCheckBalance->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnCheckBalance->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnCheckBalance->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCheckBalance->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnCheckBalance->Location = System::Drawing::Point(559, 3);
			this->btnCheckBalance->Name = L"btnCheckBalance";
			this->btnCheckBalance->Size = System::Drawing::Size(272, 192);
			this->btnCheckBalance->TabIndex = 6;
			this->btnCheckBalance->Text = L"CheckBalance";
			this->btnCheckBalance->UseVisualStyleBackColor = false;
			this->btnCheckBalance->Click += gcnew System::EventHandler(this, &SavingForm::btnCheckBalance_Click);
			// 
			// btnDeposit
			// 
			this->btnDeposit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnDeposit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnDeposit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDeposit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnDeposit->Location = System::Drawing::Point(3, 3);
			this->btnDeposit->Name = L"btnDeposit";
			this->btnDeposit->Size = System::Drawing::Size(272, 192);
			this->btnDeposit->TabIndex = 4;
			this->btnDeposit->Text = L"Deposit";
			this->btnDeposit->UseVisualStyleBackColor = false;
			this->btnDeposit->Click += gcnew System::EventHandler(this, &SavingForm::btnDeposit_Click);
			// 
			// btnTransfer
			// 
			this->btnTransfer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnTransfer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnTransfer->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTransfer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnTransfer->Location = System::Drawing::Point(281, 3);
			this->btnTransfer->Name = L"btnTransfer";
			this->btnTransfer->Size = System::Drawing::Size(272, 192);
			this->btnTransfer->TabIndex = 5;
			this->btnTransfer->Text = L"Transfer";
			this->btnTransfer->UseVisualStyleBackColor = false;
			this->btnTransfer->Click += gcnew System::EventHandler(this, &SavingForm::btnTransfer_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->btnPrev, 0, 0);
			this->tableLayoutPanel2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tableLayoutPanel2->Location = System::Drawing::Point(19, 384);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(164, 43);
			this->tableLayoutPanel2->TabIndex = 17;
			// 
			// SavingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(214)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->ClientSize = System::Drawing::Size(1150, 453);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->lbTransactionType);
			this->Controls->Add(this->btnLogout);
			this->MinimumSize = System::Drawing::Size(1168, 500);
			this->Name = L"SavingForm";
			this->Text = L"SavingForm";
			this->Load += gcnew System::EventHandler(this, &SavingForm::SavingForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//Opens deposit form and hides current form
	private: System::Void btnDeposit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		//Sends a handle of the customer to the next form in order to perform future queries as well as a handle to this form so prev button will function
		DepositForm^ f1 = gcnew DepositForm(obj, this, cID);
		f1->ShowDialog();
	}
	//Opens transfer form and hides current form
	private: System::Void btnTransfer_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		//Sends a handle of the customer to the next form in order to perform future queries as well as a handle to this form so prev button will function
		TransferForm^ f2 = gcnew TransferForm(obj, this, cID);
		f2->ShowDialog();
	}
	//Opens check balance form and hides current form
	private: System::Void btnCheckBalance_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		//Sends a handle of the customer to the next form in order to perform future queries as well as a handle to this form so prev button will function
		CheckBalanceForm^ f3 = gcnew CheckBalanceForm(obj, this, cID);
		f3->ShowDialog();
	}

	//Hides this form and shows previous one
	private: System::Void btnPrev_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		prev->Show();
	}
	//Allows user to logout of their account
	private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
		//Sends conformation box asking user if they want to logout
		if (MessageBox::Show("Do you really want to logout?", "ATM System", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			//takes user back to login page
			this->Close();
			obj->Show();
		}
		else
		{
			//Do nothing
		}
	}
private: System::Void SavingForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	//Sends a handle of the customer to the next form in order to perform future queries as well as a handle to this form so prev button will function
	TransactionHistoryForm^ f4 = gcnew TransactionHistoryForm(obj, this, cID);
	f4->ShowDialog();
}
};
}