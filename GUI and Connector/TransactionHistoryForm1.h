#pragma once

namespace TestGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for TransactionHistoryForm
	/// </summary>
	public ref class TransactionHistoryForm : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		Form^ prev;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ btnLogout;
	private: System::Windows::Forms::Button^ btnPrev;
	private: System::Windows::Forms::Label^ lbTransactionType;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	public:
		String^ cID;
		TransactionHistoryForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		TransactionHistoryForm(Form^ _obj)
		{
			obj = _obj;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		TransactionHistoryForm(Form^ _obj, Form^ _prev)
		{
			obj = _obj;
			prev = _prev;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		TransactionHistoryForm(Form^ _obj, Form^ _prev, String^ _cID)
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
		~TransactionHistoryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnRefresh;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnPrev = (gcnew System::Windows::Forms::Button());
			this->lbTransactionType = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 50);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(728, 220);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TransactionHistoryForm::dataGridView1_CellContentClick);
			// 
			// btnRefresh
			// 
			this->btnRefresh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnRefresh->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnRefresh->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnRefresh->Location = System::Drawing::Point(3, 3);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(188, 35);
			this->btnRefresh->TabIndex = 1;
			this->btnRefresh->Text = L"Withdraw History";
			this->btnRefresh->UseVisualStyleBackColor = false;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &TransactionHistoryForm::button1_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->Location = System::Drawing::Point(197, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(206, 35);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Deposit History";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &TransactionHistoryForm::button1_Click_1);
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnLogout->BackColor = System::Drawing::Color::MistyRose;
			this->btnLogout->Location = System::Drawing::Point(636, 12);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(108, 32);
			this->btnLogout->TabIndex = 12;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &TransactionHistoryForm::btnLogout_Click);
			// 
			// btnPrev
			// 
			this->btnPrev->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnPrev->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnPrev->Location = System::Drawing::Point(3, 3);
			this->btnPrev->Name = L"btnPrev";
			this->btnPrev->Size = System::Drawing::Size(132, 32);
			this->btnPrev->TabIndex = 13;
			this->btnPrev->Text = L"Prev";
			this->btnPrev->UseVisualStyleBackColor = false;
			this->btnPrev->Click += gcnew System::EventHandler(this, &TransactionHistoryForm::btnPrev_Click);
			// 
			// lbTransactionType
			// 
			this->lbTransactionType->AutoSize = true;
			this->lbTransactionType->BackColor = System::Drawing::Color::Transparent;
			this->lbTransactionType->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTransactionType->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->lbTransactionType->Location = System::Drawing::Point(8, 21);
			this->lbTransactionType->Name = L"lbTransactionType";
			this->lbTransactionType->Size = System::Drawing::Size(177, 23);
			this->lbTransactionType->TabIndex = 14;
			this->lbTransactionType->Text = L"Transaction History";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				47.84173F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				52.15827F)));
			this->tableLayoutPanel1->Controls->Add(this->btnRefresh, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->button1, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(338, 324);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(406, 41);
			this->tableLayoutPanel1->TabIndex = 15;
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
			this->tableLayoutPanel2->Location = System::Drawing::Point(12, 324);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(138, 38);
			this->tableLayoutPanel2->TabIndex = 18;
			// 
			// TransactionHistoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(214)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->ClientSize = System::Drawing::Size(756, 387);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->lbTransactionType);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->dataGridView1);
			this->MaximumSize = System::Drawing::Size(774, 434);
			this->MinimumSize = System::Drawing::Size(774, 434);
			this->Name = L"TransactionHistoryForm";
			this->Text = L"TransactionHistoryForm";
			this->Load += gcnew System::EventHandler(this, &TransactionHistoryForm::TransactionHistoryForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ accountNo = "";
		String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
		MySqlConnection^ conDatabaseGetCID = gcnew MySqlConnection(consting);
		MySqlConnection^ conDatabaseChecking = gcnew MySqlConnection(consting);
		MySqlConnection^ conDatabaseSaving = gcnew MySqlConnection(consting);
		
		
		if (prev->Text == L"CheckingForm")
		{
			//Create query to get a join of withdraw transaction information for specified checking acount
			MySqlCommand^ cmDataBaseChecking = gcnew MySqlCommand("SELECT * FROM atm_system.checking INNER JOIN atm_system.accounts ON atm_system.checking.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabaseChecking);
			MySqlDataReader^ myReaderChecking;
			try
			{
				//Execute query to get checking account balance
				conDatabaseChecking->Open();
				myReaderChecking = cmDataBaseChecking->ExecuteReader();
				if (myReaderChecking->Read())
				{
					//Get accountNo
					accountNo = myReaderChecking->GetInt32("accountNo").ToString();

					//Executes query to get a join of withdraw transaction information for specified checking acount
					MySqlCommand^ cmDataBase = gcnew MySqlCommand(" SELECT atm_system.transaction.*, atm_system.withdraw.ammountWithdrawn FROM atm_system.transaction INNER JOIN atm_system.withdraw ON atm_system.withdraw.transactionID = atm_system.transaction.transactionID WHERE accountNo = '" + accountNo + "' ORDER BY atm_system.transaction.dateOfTransaction, atm_system.transaction.timeOfTransaction;", conDatabase);
					MySqlDataReader^ myReader;

					//Populates the on screen table with relevant information
					MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
					sda->SelectCommand = cmDataBase;
					DataTable^ dbdataset = gcnew DataTable();
					sda->Fill(dbdataset);
					BindingSource^ bSource = gcnew BindingSource();

					bSource->DataSource = dbdataset;
					dataGridView1->DataSource = bSource;
					sda->Update(dbdataset);
				}
				
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
		else if (prev->Text == L"SavingForm")
		{
			//Create query to get a join of withdraw transaction information for specified savings acount
			MySqlCommand^ cmDataBaseSaving = gcnew MySqlCommand("SELECT * FROM atm_system.saving INNER JOIN atm_system.accounts ON atm_system.saving.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabaseSaving);
			MySqlDataReader^ myReaderSaving;
			try
			{
				//Execute query to get checking account balance
				conDatabaseSaving->Open();
				myReaderSaving = cmDataBaseSaving->ExecuteReader();
				if (myReaderSaving->Read())
				{
					//Get accountNo
					accountNo = myReaderSaving->GetInt32("accountNo").ToString();

					//Executes query to get a join of withdraw transaction information for specified checking acount
					MySqlCommand^ cmDataBase = gcnew MySqlCommand(" SELECT atm_system.transaction.*, atm_system.withdraw.ammountWithdrawn FROM atm_system.transaction INNER JOIN atm_system.withdraw ON atm_system.withdraw.transactionID = atm_system.transaction.transactionID WHERE accountNo = '" + accountNo + "' ORDER BY atm_system.transaction.dateOfTransaction, atm_system.transaction.timeOfTransaction;", conDatabase);
					MySqlDataReader^ myReader;

					//Populates the onscreen table with relevent info
					MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
					sda->SelectCommand = cmDataBase;
					DataTable^ dbdataset = gcnew DataTable();
					sda->Fill(dbdataset);
					BindingSource^ bSource = gcnew BindingSource();

					bSource->DataSource = dbdataset;
					dataGridView1->DataSource = bSource;
					sda->Update(dbdataset);
				}

			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
		conDatabase->Close();
		conDatabaseChecking->Close();
		conDatabaseGetCID->Close();
		conDatabaseSaving->Close();
	}

	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		String^ accountNo = "";
		String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
		MySqlConnection^ conDatabaseGetCID = gcnew MySqlConnection(consting);
		MySqlConnection^ conDatabaseChecking = gcnew MySqlConnection(consting);
		MySqlConnection^ conDatabaseSaving = gcnew MySqlConnection(consting);
		

		if (prev->Text == L"CheckingForm")
		{
			//Create query to get a join of deposit transaction information for specified checking acount
			MySqlCommand^ cmDataBaseChecking = gcnew MySqlCommand("SELECT * FROM atm_system.checking INNER JOIN atm_system.accounts ON atm_system.checking.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabaseChecking);
			MySqlDataReader^ myReaderChecking;
			try
			{
				//Execute query to get checking account balance
				conDatabaseChecking->Open();
				myReaderChecking = cmDataBaseChecking->ExecuteReader();
				if (myReaderChecking->Read())
				{
					//Get accountNo
					accountNo = myReaderChecking->GetInt32("accountNo").ToString();

					//Executes query to get a join of deposit transaction information for specified checking acount
					MySqlCommand^ cmDataBase = gcnew MySqlCommand(" SELECT atm_system.transaction.*, atm_system.deposit.ammountDeposited FROM atm_system.transaction INNER JOIN atm_system.deposit ON atm_system.deposit.transactionID = atm_system.transaction.transactionID WHERE accountNo = '" + accountNo + "' ORDER BY atm_system.transaction.dateOfTransaction, atm_system.transaction.timeOfTransaction;", conDatabase);
					MySqlDataReader^ myReader;

					//Populates onscreen table with relevant info
					MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
					sda->SelectCommand = cmDataBase;
					DataTable^ dbdataset = gcnew DataTable();
					sda->Fill(dbdataset);
					BindingSource^ bSource = gcnew BindingSource();

					bSource->DataSource = dbdataset;
					dataGridView1->DataSource = bSource;
					sda->Update(dbdataset);
				}

			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
		else if (prev->Text == L"SavingForm")
		{
			//Create query to get a join of deposit transaction information for specified savings acount
			MySqlCommand^ cmDataBaseSaving = gcnew MySqlCommand("SELECT * FROM atm_system.saving INNER JOIN atm_system.accounts ON atm_system.saving.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabaseSaving);
			MySqlDataReader^ myReaderSaving;
			try
			{
				//Execute query to get checking account balance
				conDatabaseSaving->Open();
				myReaderSaving = cmDataBaseSaving->ExecuteReader();
				if (myReaderSaving->Read())
				{
					//Get accountNo
					accountNo = myReaderSaving->GetInt32("accountNo").ToString();

					//Executes query to get a join of deposit transaction information for specified savings acount
					MySqlCommand^ cmDataBase = gcnew MySqlCommand(" SELECT atm_system.transaction.*, atm_system.deposit.ammountDeposited FROM atm_system.transaction INNER JOIN atm_system.deposit ON atm_system.deposit.transactionID = atm_system.transaction.transactionID WHERE accountNo = '" + accountNo + "' ORDER BY atm_system.transaction.dateOfTransaction, atm_system.transaction.timeOfTransaction;", conDatabase);
					MySqlDataReader^ myReader;

					//Populates onscreen table with relevant info
					MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
					sda->SelectCommand = cmDataBase;
					DataTable^ dbdataset = gcnew DataTable();
					sda->Fill(dbdataset);
					BindingSource^ bSource = gcnew BindingSource();

					bSource->DataSource = dbdataset;
					dataGridView1->DataSource = bSource;
					sda->Update(dbdataset);
				}

			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
		conDatabase->Close();
		conDatabaseChecking->Close();
		conDatabaseGetCID->Close();
		conDatabaseSaving->Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

		   //Allows user to logout
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
private: System::Void TransactionHistoryForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

	   //Hides this form and shows previous one
private: System::Void btnPrev_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	prev->Show();
}
};
}
