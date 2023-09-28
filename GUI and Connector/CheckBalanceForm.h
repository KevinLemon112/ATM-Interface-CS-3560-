#pragma once
#include <cmath>
namespace TestGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for CheckBalanceForm
	/// </summary>
	public ref class CheckBalanceForm : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		Form^ prev;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	public:
		String^ cID;
		CheckBalanceForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		CheckBalanceForm(Form^ _obj)
		{
			obj = _obj;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		CheckBalanceForm(Form^ _obj, Form^ _prev)
		{
			obj = _obj;
			prev = _prev;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		CheckBalanceForm(Form^ _obj, String^ _cID)
		{
			obj = _obj;
			cID = _cID;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		CheckBalanceForm(Form^ _obj, Form^ _prev, String^ _cID)
		{
			obj = _obj;
			prev = _prev;
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
		~CheckBalanceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbCurBalance;
	protected:

	private: System::Windows::Forms::Label^ lbCurrentBalance;
	private: System::Windows::Forms::Button^ btnLogout;
	private: System::Windows::Forms::Button^ btnPrev;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		//rounds up doubles
		double round_up(double value, int decimal_places) {
			const double multiplier = std::pow(10.0, decimal_places);
			return std::ceil(value * multiplier) / multiplier;
		}
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		/// 
		void InitializeComponent(void)
		{
			this->lbCurBalance = (gcnew System::Windows::Forms::Label());
			this->lbCurrentBalance = (gcnew System::Windows::Forms::Label());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnPrev = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbCurBalance
			// 
			this->lbCurBalance->AutoSize = true;
			this->lbCurBalance->BackColor = System::Drawing::Color::Transparent;
			this->lbCurBalance->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCurBalance->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->lbCurBalance->Location = System::Drawing::Point(12, 26);
			this->lbCurBalance->Name = L"lbCurBalance";
			this->lbCurBalance->Size = System::Drawing::Size(149, 23);
			this->lbCurBalance->TabIndex = 4;
			this->lbCurBalance->Text = L"Current Balance";
			// 
			// lbCurrentBalance
			// 
			this->lbCurrentBalance->AutoSize = true;
			this->lbCurrentBalance->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->lbCurrentBalance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbCurrentBalance->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbCurrentBalance->Location = System::Drawing::Point(12, 85);
			this->lbCurrentBalance->Name = L"lbCurrentBalance";
			this->lbCurrentBalance->Size = System::Drawing::Size(131, 24);
			this->lbCurrentBalance->TabIndex = 5;
			this->lbCurrentBalance->Text = L"Click To Show";
			this->lbCurrentBalance->Click += gcnew System::EventHandler(this, &CheckBalanceForm::lbCurrentBalance_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnLogout->BackColor = System::Drawing::Color::MistyRose;
			this->btnLogout->Location = System::Drawing::Point(283, 12);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(108, 32);
			this->btnLogout->TabIndex = 12;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &CheckBalanceForm::btnLogout_Click);
			// 
			// btnPrev
			// 
			this->btnPrev->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnPrev->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnPrev->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnPrev->Location = System::Drawing::Point(3, 3);
			this->btnPrev->Name = L"btnPrev";
			this->btnPrev->Size = System::Drawing::Size(82, 32);
			this->btnPrev->TabIndex = 13;
			this->btnPrev->Text = L"Prev";
			this->btnPrev->UseVisualStyleBackColor = false;
			this->btnPrev->Click += gcnew System::EventHandler(this, &CheckBalanceForm::btnPrev_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->btnPrev, 0, 0);
			this->tableLayoutPanel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 158);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(88, 38);
			this->tableLayoutPanel1->TabIndex = 14;
			// 
			// CheckBalanceForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(214)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->ClientSize = System::Drawing::Size(403, 208);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->lbCurrentBalance);
			this->Controls->Add(this->lbCurBalance);
			this->MaximumSize = System::Drawing::Size(421, 255);
			this->MinimumSize = System::Drawing::Size(421, 255);
			this->Name = L"CheckBalanceForm";
			this->Text = L"CheckBalanceForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//Displays current balance after user presses on label
	private: System::Void lbCurrentBalance_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ curBalance = "";
		//Make a connecion to MySql using log in credentials
		String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
		//Check whether the user is in Checking or Savings Mode
		if (prev->Text == L"CheckingForm")
		{
			//Create query to get user data from checking and account tables
			MySqlCommand^ cmDataBase = gcnew MySqlCommand("SELECT * FROM atm_system.checking INNER JOIN atm_system.accounts ON atm_system.checking.accountNo=atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase);
			MySqlDataReader^ myReader;
			try
			{
				//Initiate the connection to the database and execute the query
				conDatabase->Open();
				myReader = cmDataBase->ExecuteReader();

				//Find the curBalance of user's checking account and stores it in curBalance
				if (myReader->Read())
				{
					curBalance = round_up(myReader->GetDouble("balance"), 2).ToString();
				}
			}
			//Throw an exception if error happens
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
		else if (prev->Text == L"SavingForm")
		{
			//Create query to get user data from saving and account tables
			MySqlCommand^ cmDataBase = gcnew MySqlCommand("SELECT * FROM atm_system.saving INNER JOIN atm_system.accounts ON atm_system.saving.accountNo=atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase);
			MySqlDataReader^ myReader;
			try
			{
				//Initiate the connection to the database and execute the query
				conDatabase->Open();
				myReader = cmDataBase->ExecuteReader();

				//Find the curBalance of user's savings account and stores it in curBalance
				if (myReader->Read())
				{
					curBalance = round_up(myReader->GetDouble("balance"), 2).ToString();
				}
			}
			//Throw an exception if error happens
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
		//Display the balance to the user
		this->lbCurrentBalance->Text = L"Current Balance: $" + curBalance;
		conDatabase->Close();
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
			//do nothing
		}
	}
};
}
