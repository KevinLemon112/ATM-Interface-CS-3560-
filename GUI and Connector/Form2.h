#pragma once
#include "CheckingForm.h"
#include "SavingForm.h"
namespace TestGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		String^ cID;
		Form2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Form2(Form^ _obj)
		{
			obj = _obj;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Form2(Form^ _obj, String^ _cID)
		{
			obj = _obj;
			cID = _cID;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnChecking;
	private: System::Windows::Forms::Button^ btnSaving;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ lbTransactionType;
	private: System::Windows::Forms::Button^ btnLogout;


	protected:

	protected:

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
			this->btnChecking = (gcnew System::Windows::Forms::Button());
			this->btnSaving = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lbTransactionType = (gcnew System::Windows::Forms::Label());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnChecking
			// 
			this->btnChecking->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnChecking->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnChecking->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnChecking->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnChecking->Location = System::Drawing::Point(3, 3);
			this->btnChecking->Name = L"btnChecking";
			this->btnChecking->Size = System::Drawing::Size(433, 265);
			this->btnChecking->TabIndex = 4;
			this->btnChecking->Text = L"Checking";
			this->btnChecking->UseVisualStyleBackColor = false;
			this->btnChecking->Click += gcnew System::EventHandler(this, &Form2::btnChecking_Click);
			// 
			// btnSaving
			// 
			this->btnSaving->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSaving->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnSaving->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSaving->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnSaving->Location = System::Drawing::Point(442, 3);
			this->btnSaving->Name = L"btnSaving";
			this->btnSaving->Size = System::Drawing::Size(433, 265);
			this->btnSaving->TabIndex = 5;
			this->btnSaving->Text = L"Saving";
			this->btnSaving->UseVisualStyleBackColor = false;
			this->btnSaving->Click += gcnew System::EventHandler(this, &Form2::btnSaving_Click);
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
			this->tableLayoutPanel1->Controls->Add(this->btnSaving, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnChecking, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(29, 102);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(878, 271);
			this->tableLayoutPanel1->TabIndex = 6;
			// 
			// lbTransactionType
			// 
			this->lbTransactionType->AutoSize = true;
			this->lbTransactionType->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTransactionType->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->lbTransactionType->Location = System::Drawing::Point(25, 50);
			this->lbTransactionType->Name = L"lbTransactionType";
			this->lbTransactionType->Size = System::Drawing::Size(242, 23);
			this->lbTransactionType->TabIndex = 8;
			this->lbTransactionType->Text = L"Please Select Account Type";
			this->lbTransactionType->Click += gcnew System::EventHandler(this, &Form2::lbTransactionType_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->BackColor = System::Drawing::Color::MistyRose;
			this->btnLogout->Location = System::Drawing::Point(809, 21);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(127, 32);
			this->btnLogout->TabIndex = 9;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &Form2::btnLogout_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(214)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->ClientSize = System::Drawing::Size(948, 445);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->lbTransactionType);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MaximumSize = System::Drawing::Size(966, 492);
			this->MinimumSize = System::Drawing::Size(966, 492);
			this->Name = L"Form2";
			this->Text = L"Account Selection";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Opens checking form and hides current form
	private: System::Void btnChecking_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		//Sends a handle of the customer to the next form in order to perform future queries as well as a handle to this form so prev button will function
		CheckingForm^ f1 = gcnew CheckingForm(obj, this, cID);
		f1->ShowDialog();
	}
	//Opens saving form and hides current form
	private: System::Void btnSaving_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		//Sends a handle of the customer to the next form in order to perform future queries as well as a handle to this form so prev button will function
		SavingForm^ f2 = gcnew SavingForm(obj, this, cID);
		f2->ShowDialog();
	}

	//Allows user to logout of their account
	private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
		//Sends conformation box asking user if they want to logout
		if (MessageBox::Show("Do you really want to logout?", "ATM System", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			//takes user back to login page
			this->Hide();
			obj->Show();
		}
		else
		{
			//Do nothing
		}
	}
	private: System::Void lbTransactionType_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Form2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}