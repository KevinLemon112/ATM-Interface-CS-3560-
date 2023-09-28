#pragma once
#include <cmath>
#include <windows.h>
namespace TestGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for TransferForm
	/// </summary>
	public ref class TransferForm : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		Form^ prev;
		String^ transferDir = "";
	private: System::Windows::Forms::Button^ btnPrev;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::RadioButton^ rbtnSavingToChecking;
	private: System::Windows::Forms::RadioButton^ rbtnCheckingToSaving;



	public:
		String^ cID;
		TransferForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		TransferForm(Form^ _obj)
		{
			obj = _obj;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		TransferForm(Form^ _obj, Form^ _prev)
		{
			obj = _obj;
			prev = _prev;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		TransferForm(Form^ _obj, String^ _cID)
		{
			obj = _obj;
			cID = _cID;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		TransferForm(Form^ _obj, Form^ _prev, String^ _cID)
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
		~TransferForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbTransferAmount;
	protected:

	private: System::Windows::Forms::TextBox^ tbTransfer;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::Button^ btnLogout;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		//Rounds up a double
		double round_up(double value, int decimal_places) {
			const double multiplier = std::pow(10.0, decimal_places);
			return std::ceil(value * multiplier) / multiplier;
		}
		//Test function can be ignored
		void makeTransfera(String^ transactionID, String^ transferAmount, String^ date, String^ time)
		{
			String^ checkingBalance = "";
			String^ savingBalance = "";
			String^ newSavingsBalance = "";
			String^ newCheckingBalance = "";
			String^ accountNoChecking = "";
			String^ accountNoSaving = "";
			//Make connecions to MySql using log in credentials
			String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
			MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabase1 = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabase2 = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseInsertToDeposit = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseInsertToWithdraw = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseInsertToTransaction = gcnew MySqlConnection(consting);
			//Check whether the user is in Checking or Savings Mode
			if (prev->Text == L"CheckingForm")
			{
				//Create query to update checking account balance (deposit)
				MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance + '" + this->tbTransfer->Text + "' where customerID = '" + cID + "';", conDatabase);
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.checking INNER JOIN atm_system.accounts ON atm_system.checking.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				//Create query to update checking account balance (withdraw)
				MySqlCommand^ cmDataBase2 = gcnew MySqlCommand("update atm_system.accounts set balance = balance - '" + this->tbTransfer->Text + "' where customerID = '" + cID + "';", conDatabase2);
				MySqlDataReader^ myReader;
				MySqlDataReader^ myReader1;
				MySqlDataReader^ myReader2;

				try
				{
					//Execute query to update checking account balance (deposit)
					conDatabase->Open();
					myReader = cmDataBase->ExecuteReader();

					//Execute query to get checking account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Execute query to update checking account balance (withdraw)
					conDatabase2->Open();
					myReader2 = cmDataBase2->ExecuteReader();

					//Store the current saving account balance and accountNo into variables
					if (myReader1->Read())
					{
						newSavingsBalance = round_up(myReader1->GetDouble("balance"), 2).ToString();
						accountNoSaving = myReader1->GetInt32("accountNo").ToString();
					}

					//Store the current checking account balance and accountNo into variables
					if (myReader2->Read())
					{
						newCheckingBalance = round_up(myReader2->GetDouble("balance"), 2).ToString();
						accountNoChecking = myReader2->GetInt32("accountNo").ToString();
					}

					//Create query to insert a new entry into Transaction table
					MySqlCommand^ cmDataBaseInsertToTransaction = gcnew MySqlCommand("insert into atm_system.transaction (transactionid, accountno, dateoftransaction, timeoftransaction) values ('" + transactionID + "', '" + accountNoSaving + "', '" + date + "', '" + time + "');", conDatabaseInsertToTransaction);
					//Create query to insert a new entry into Deposit table
					MySqlCommand^ cmDataBaseInsertToDeposit = gcnew MySqlCommand("insert into atm_system.deposit (transactionid, ammountdeposited) values ('" + transactionID + "', '" + this->tbTransfer->Text + "');", conDatabaseInsertToDeposit);
					//Create query to insert a new entry into Withdraw table
					MySqlCommand^ cmDataBaseInsertToWithdraw = gcnew MySqlCommand("insert into atm_system.withdraw (transactionid, ammountwithdrawn) values ('" + transactionID + "', '" + this->tbTransfer->Text + "');", conDatabaseInsertToWithdraw);
					MySqlDataReader^ myReaderInsertToTransaction;
					MySqlDataReader^ myReaderInsertToDeposit;
					MySqlDataReader^ myReaderInsertToWithdraw;

					//Execute query to insert a new entry into Transaction table
					conDatabaseInsertToTransaction->Open();
					myReaderInsertToTransaction = cmDataBaseInsertToTransaction->ExecuteReader();

					//Execute query to insert a new entry into Deposit table
					conDatabaseInsertToDeposit->Open();
					myReaderInsertToDeposit = cmDataBaseInsertToDeposit->ExecuteReader();

					//Execute query to insert a new entry into Withdraw table
					conDatabaseInsertToWithdraw->Open();
					myReaderInsertToWithdraw = cmDataBaseInsertToWithdraw->ExecuteReader();

					//Display Success Message box with current checking and saving balance
					MessageBox::Show("You Have Succsesfully Transfering $" + transferAmount + " into your checkings account. \nCurrent checking balance is $" + newCheckingBalance + "\nCurrent savings balance is $" + newSavingsBalance);
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
			else if (prev->Text == L"SavingForm")
			{
				//Create query to update checking account balance (deposit)
				MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance + '" + this->tbTransfer->Text + "' where customerID = '" + cID + "';", conDatabase);
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.saving INNER JOIN atm_system.accounts ON atm_system.saving.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				//Create query to update checking account balance (withdraw)
				MySqlCommand^ cmDataBase2 = gcnew MySqlCommand("update atm_system.accounts set balance = balance - '" + this->tbTransfer->Text + "' where customerID = '" + cID + "';", conDatabase2);
				MySqlDataReader^ myReader;
				MySqlDataReader^ myReader1;
				MySqlDataReader^ myReader2;

				try
				{
					//Execute query to update checking account balance (deposit)
					conDatabase->Open();
					myReader = cmDataBase->ExecuteReader();

					//Execute query to get checking account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Create query to update checking account balance (withdraw)
					conDatabase2->Open();
					myReader2 = cmDataBase2->ExecuteReader();

					//Store the current checking account balance and accountNo into variables
					if (myReader1->Read())
					{
						newCheckingBalance = round_up(myReader1->GetDouble("balance"), 2).ToString();
						accountNoChecking = myReader1->GetInt32("accountNo").ToString();
					}

					//Store the current saving account balance and accountNo into variables
					if (myReader2->Read())
					{
						newSavingsBalance = round_up(myReader2->GetDouble("balance"), 2).ToString();
						accountNoSaving = myReader2->GetInt32("accountNo").ToString();
					}

					//Create query to insert a new entry into Transaction table
					MySqlCommand^ cmDataBaseInsertToTransaction = gcnew MySqlCommand("insert into atm_system.transaction (transactionid, accountno, dateoftransaction, timeoftransaction) values ('" + transactionID + "', '" + accountNoSaving + "', '" + date + "', '" + time + "');", conDatabaseInsertToTransaction);
					//Create query to insert a new entry into Deposit table
					MySqlCommand^ cmDataBaseInsertToDeposit = gcnew MySqlCommand("insert into atm_system.deposit (transactionid, ammountdeposited) values ('" + transactionID + "', '" + this->tbTransfer->Text + "');", conDatabaseInsertToDeposit);
					//Create query to insert a new entry into Withdraw table
					MySqlCommand^ cmDataBaseInsertToWithdraw = gcnew MySqlCommand("insert into atm_system.withdraw (transactionid, ammountwithdrawn) values ('" + transactionID + "', '" + this->tbTransfer->Text + "');", conDatabaseInsertToWithdraw);
					MySqlDataReader^ myReaderInsertToTransaction;
					MySqlDataReader^ myReaderInsertToDeposit;
					MySqlDataReader^ myReaderInsertToWithdraw;

					//Execute query to insert a new entry into Transaction table
					conDatabaseInsertToTransaction->Open();
					myReaderInsertToTransaction = cmDataBaseInsertToTransaction->ExecuteReader();

					//Execute query to insert a new entry into Deposit table
					conDatabaseInsertToDeposit->Open();
					myReaderInsertToDeposit = cmDataBaseInsertToDeposit->ExecuteReader();

					//Execute query to insert a new entry into Withdraw table
					conDatabaseInsertToWithdraw->Open();
					myReaderInsertToWithdraw = cmDataBaseInsertToWithdraw->ExecuteReader();

					//Display Success Message box with current checking and saving balance
					MessageBox::Show("You Have Succsesfully Transfering $" + transferAmount + " into your checkings account. \nCurrent checking balance is $" + newCheckingBalance + "\nCurrent savings balance is $" + newSavingsBalance);
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}

			}
			conDatabase->Close();
			conDatabase1->Close();
			conDatabase2->Close();
			conDatabaseInsertToWithdraw->Close();
			conDatabaseInsertToTransaction->Close();
			conDatabaseInsertToDeposit->Close();
		}
		
		bool checkIfDepositIsValid(String^ depositAmount, String^ date, String^ time, String^ accountType)
		{
			String^ newBalance = "";
			String^ accountNo = "";
			double minDeposit;
			double minBalance;
			int curTranID;
			int transactionID = NULL;
			//Make connecions to MySql using log in credentials
			String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
			MySqlConnection^ conDatabase1 = gcnew MySqlConnection(consting);

			//Check whether the user is in Checking or Savings Mode
			if (accountType == L"Checking")
			{
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.checking INNER JOIN atm_system.accounts ON atm_system.checking.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader1;

				try
				{
					//Execute query to get checking account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Store the current checking account balance and accountNo into variables
					if (myReader1->Read())
					{
						accountNo = myReader1->GetInt32("accountNo").ToString();
						return true;
					}
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
					return false;
				}
			}
			else if (accountType == L"Saving")
			{
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.saving INNER JOIN atm_system.accounts ON atm_system.saving.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader1;

				try
				{
					//Execute query to get saving account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Store the current saving account balance and accountNo into variables
					if (myReader1->Read())
					{
						minDeposit = round_up(myReader1->GetDouble("minDeposit"), 2);
						accountNo = myReader1->GetInt32("accountNo").ToString();
						if (minDeposit < Double::Parse(depositAmount))
						{
							return true;
						}
						else
						{
							MessageBox::Show("Error: You must transfer an amount greater than  $" + minDeposit + " into account "+accountNo+"!", "ATM System", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return false;
						}

					}

				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
					return false;
				}

			}
			conDatabase1->Close();
		}
		bool checkIfWithdrawIsValid(String^ withdrawAmount, String^ date, String^ time, String^ accountType)
		{
			double curBalance;
			String^ newBalance = "";
			String^ accountNo = "";
			double minBalance;
			double maxWithdraw;
			int curTranID;
			int transactionID = NULL;
			//Make connecions to MySql using log in credentials
			String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
			MySqlConnection^ conDatabase1 = gcnew MySqlConnection(consting);

			//Check whether the user is in Checking or Savings Mode
			if (accountType == L"Checking")
			{
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.checking INNER JOIN atm_system.accounts ON atm_system.checking.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader1;

				try
				{
					//Execute query to get checking account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Store the current checking account balance and accountNo into variables
					if (myReader1->Read())
					{
						accountNo = myReader1->GetInt32("accountNo").ToString();
						curBalance = round_up(myReader1->GetDouble("balance"), 2);
						maxWithdraw = round_up(myReader1->GetDouble("maxWithdrawAmt"), 2);
						minBalance = round_up(myReader1->GetDouble("minBalance"), 2);
						if (minBalance <= curBalance - Double::Parse(withdrawAmount))
						{
							if (maxWithdraw >= Double::Parse(withdrawAmount))
							{
								return true;
							}
							else
							{
								MessageBox::Show("Error: Account " + accountNo + " can only have a maximum of $" + maxWithdraw + " withdrawn. Please enter a new transfer amount.", "ATM System", MessageBoxButtons::OK, MessageBoxIcon::Error);
								return false;
							}
						}
						else if (minBalance > curBalance - Double::Parse(withdrawAmount))
						{
							//Display error
							MessageBox::Show("Error: You will be $" + (minBalance - (curBalance - Double::Parse(withdrawAmount))) + " below your minimum balance for account " + accountNo + " which must have a minimum balance of $" + minBalance + ".Please enter a new transfer amount ", "ATM System", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return false;
						}

					}
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
					return false;
				}
			}
			else if (accountType == L"Saving")
			{
				//Create query to get user data from savings and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.saving INNER JOIN atm_system.accounts ON atm_system.saving.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader1;

				try
				{
					//Execute query to get saving account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Store the current saving account balance and accountNo into variables
					if (myReader1->Read())
					{
						curBalance = round_up(myReader1->GetDouble("balance"), 2);
						minBalance = round_up(myReader1->GetDouble("minBalance"), 2);
						if (minBalance <= curBalance - Double::Parse(withdrawAmount))
						{
							accountNo = myReader1->GetInt32("accountNo").ToString();
							return true;
						}
						else if (minBalance > curBalance - Double::Parse(withdrawAmount))
						{
							MessageBox::Show("Error: You will be $" + (minBalance - (curBalance - Double::Parse(withdrawAmount))) + " below your minimum balance for account " + accountNo + " which must have a minimum balance of $" + minBalance + ".Please enter a new transfer amount ", "ATM System", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return false;
						}
					}
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
					return false;
				}
			}
			conDatabase1->Close();
		}

		//Overloaded versions of makeDeposit and makeWithdraw that are meant to be used for transfers in case of overdraft
		void makeDeposit(String^ depositAmount, String^ date, String^ time,String^ accountType)
		{
			//tbDebug->Text += "In Deposit";
			String^ newBalance = "";
			String^ accountNo = "";
			double minDeposit;
			double minBalance;
			int curTranID;
			int transactionID = NULL;
			//Make connecions to MySql using log in credentials
			String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
			MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabase1 = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseInsertToDeposit = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseInsertToTransaction = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseGetCurrentTransactionID = gcnew MySqlConnection(consting);
			
			//Create query to get current transaction id
			MySqlCommand^ cmDataBaseGetCurrentTransactionID = gcnew MySqlCommand("SELECT max(transactionid) from atm_system.transaction;", conDatabaseGetCurrentTransactionID);
			MySqlDataReader^ myReaderGetCurrentTransactionID;
			//Check whether the user is in Checking or Savings Mode
			if (accountType == L"Checking")
			{
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.checking INNER JOIN atm_system.accounts ON atm_system.checking.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);				
				MySqlDataReader^ myReader1;
				
				
				try
				{
					//Execute query to get checking account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Store the current checking account balance and accountNo into variables
					if (myReader1->Read())
					{
						accountNo = myReader1->GetInt32("accountNo").ToString();
						
						//Create query to update checking account balance
						MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance + '" + depositAmount + "' where customerID = '" + cID + "' and accountNo = '" + accountNo + "';", conDatabase);
						MySqlDataReader^ myReader;

						//Execute query to update checking account balance
						conDatabase->Open();
						myReader = cmDataBase->ExecuteReader();

						newBalance = round_up(myReader1->GetDouble("balance"), 2).ToString();
					}
					//Create query to insert a new entry into Transaction table
					MySqlCommand^ cmDataBaseInsertToTransaction = gcnew MySqlCommand("insert into atm_system.transaction (transactionid, accountno, dateoftransaction, timeoftransaction) values ('" + curTranID + "', '" + accountNo + "', '" + date + "', '" + time + "');", conDatabaseInsertToTransaction);
					MySqlDataReader^ myReaderInsertToTransaction;

					//Get Current transacition id
					conDatabaseGetCurrentTransactionID->Open();
					myReaderGetCurrentTransactionID = cmDataBaseGetCurrentTransactionID->ExecuteReader();
					if (myReaderGetCurrentTransactionID->Read())
					{
						curTranID = myReaderGetCurrentTransactionID->GetInt32("max(transactionid)") + 1;
					}
					

					//Create query to insert a new entry into Deposit table
					MySqlCommand^ cmDataBaseInsertToDeposit = gcnew MySqlCommand("insert into atm_system.deposit (transactionid, ammountdeposited) values ('" + curTranID + "', '" + depositAmount + "');", conDatabaseInsertToDeposit);
					MySqlDataReader^ myReaderInsertToDeposit;

					//Execute query to insert a new entry into Transaction table
					conDatabaseInsertToTransaction->Open();
					myReaderInsertToTransaction = cmDataBaseInsertToTransaction->ExecuteReader();
					
					
					//Execute query to insert a new entry into Deposit table
					conDatabaseInsertToDeposit->Open();
					myReaderInsertToDeposit = cmDataBaseInsertToDeposit->ExecuteReader();

					//Display Success Message box with current checking balance
					//MessageBox::Show("You Have Succsesfully Deposited $" + depositAmount + " into your checkings account. \nCurrent balance is $" + newBalance);
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
			else if (accountType == L"Saving")
			{
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.saving INNER JOIN atm_system.accounts ON atm_system.saving.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader1;

				try
				{
					//Execute query to get saving account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();


					//Store the current saving account balance and accountNo into variables
					if (myReader1->Read())
					{
						minDeposit = round_up(myReader1->GetDouble("minDeposit"), 2);
						if (minDeposit < Double::Parse(depositAmount))
						{
							accountNo = myReader1->GetInt32("accountNo").ToString();

							//Create query to update saving account balance
							MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance + '" + depositAmount + "' where customerID = '" + cID + "' and accountNo = '" + accountNo + "';", conDatabase);
							MySqlDataReader^ myReader;

							//Execute query to update saving account balance
							conDatabase->Open();
							myReader = cmDataBase->ExecuteReader();
							
							newBalance = round_up(myReader1->GetDouble("balance"), 2).ToString();

						}
						else
						{
							MessageBox::Show("Error: Account " + accountNo + " must recieve an amount greater than  $" + minDeposit + "!", "ATM System", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return;
						}

					}

					//Create query to insert a new entry into Transaction table
					MySqlCommand^ cmDataBaseInsertToTransaction = gcnew MySqlCommand("insert into atm_system.transaction (transactionid, accountno, dateoftransaction, timeoftransaction) values ('" + curTranID + "', '" + accountNo + "', '" + date + "', '" + time + "');", conDatabaseInsertToTransaction);
					MySqlDataReader^ myReaderInsertToTransaction;

					//Get Current transacition id
					conDatabaseGetCurrentTransactionID->Open();
					myReaderGetCurrentTransactionID = cmDataBaseGetCurrentTransactionID->ExecuteReader();
					if (myReaderGetCurrentTransactionID->Read())
					{
						curTranID = myReaderGetCurrentTransactionID->GetInt32("max(transactionid)") + 1;
					}
				
					//Create query to insert a new entry into Deposit table
					MySqlCommand^ cmDataBaseInsertToDeposit = gcnew MySqlCommand("insert into atm_system.deposit (transactionid, ammountdeposited) values ('" + curTranID + "', '" + depositAmount + "');", conDatabaseInsertToDeposit);
					MySqlDataReader^ myReaderInsertToDeposit;

					//Execute query to insert a new entry into Transaction table
					conDatabaseInsertToTransaction->Open();
					myReaderInsertToTransaction = cmDataBaseInsertToTransaction->ExecuteReader();

					
					//Execute query to insert a new entry into Deposit table
					conDatabaseInsertToDeposit->Open();
					myReaderInsertToDeposit = cmDataBaseInsertToDeposit->ExecuteReader();

					//Display Success Message box with current savings balance
					//MessageBox::Show("You Have Succsesfully Deposited $" + depositAmount + " into your savings account. \nCurrent balance is $" + newBalance);
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
			conDatabase->Close();
			conDatabase1->Close();
			conDatabaseGetCurrentTransactionID->Close();
			conDatabaseInsertToDeposit->Close();
			conDatabaseInsertToTransaction->Close();
		}
		void makeWithdraw(String^ withdrawAmount, String^ date, String^ time, String^ accountType)
		{
			//transactionID = (Int32::Parse(transactionID) + 1).ToString();
			double curBalance;
			String^ newBalance = "";
			String^ accountNo = "";
			//String^ transactionID = "NULL";
			double minBalance;
			double maxWithdraw;
			int curTranID;
			int transactionID = NULL;
			//Make connecions to MySql using log in credentials
			String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
			MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabase1 = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseInsertToWithdraw = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseInsertToTransaction = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseGetCurrentTransactionID = gcnew MySqlConnection(consting);
			//Create query to get current transaction id
			MySqlCommand^ cmDataBaseGetCurrentTransactionID = gcnew MySqlCommand("SELECT max(transactionid) from atm_system.transaction;", conDatabaseGetCurrentTransactionID);
			MySqlDataReader^ myReaderGetCurrentTransactionID;

			//Check whether the user is in Checking or Savings Mode
			if (accountType == L"Checking")
			{
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.checking INNER JOIN atm_system.accounts ON atm_system.checking.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader1;

				try
				{
					//Execute query to get checking account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Store the current checking account balance and accountNo into variables
					if (myReader1->Read())
					{
						curBalance = round_up(myReader1->GetDouble("balance"), 2);
						maxWithdraw = round_up(myReader1->GetDouble("maxWithdrawAmt"), 2);
						minBalance = round_up(myReader1->GetDouble("minBalance"), 2);
						//tbDebug->Text +=  (curBalance - Double::Parse(withdrawAmount));
						if (minBalance <= curBalance - Double::Parse(withdrawAmount))
						{

							if (maxWithdraw > Double::Parse(withdrawAmount))
							{
								accountNo = myReader1->GetInt32("accountNo").ToString();
								//tbDebug->Text += newBalance;
								//tbDebug->Text += accountNo;
								
								//Create query to update checking account balance
								MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance - '" + withdrawAmount + "' where customerID = '" + cID + "' and accountNo = '" + accountNo + "';", conDatabase);
								MySqlDataReader^ myReader;

								//Execute query to update checking account balance
								conDatabase->Open();
								myReader = cmDataBase->ExecuteReader();

								newBalance = round_up(myReader1->GetDouble("balance"), 2).ToString();

							}
							else
							{
								//tbDebug->Text += "In eles1" + accountNo;
								MessageBox::Show("Error: Account " + accountNo + " can only transfer a maximum of $" + maxWithdraw + "'s at a time. Please enter a new transfer amount.", "ATM System", MessageBoxButtons::OK, MessageBoxIcon::Error);
								return;
							}
						}
						else if (minBalance > curBalance - Double::Parse(withdrawAmount))
						{
							//Display error
							MessageBox::Show("Error: You will be $" + (minBalance - (curBalance - Double::Parse(withdrawAmount))) + " below your minimum balance for account " + accountNo + " which must have a minimum balance of $" + minBalance + ".Please enter a new transfer amount ", "ATM System", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return;
						}

					}
					//tbDebug->Text += curTranID + accountNo;
					//Create query to insert a new entry into Transaction table
					MySqlCommand^ cmDataBaseInsertToTransaction = gcnew MySqlCommand("insert into atm_system.transaction (transactionid, accountno, dateoftransaction, timeoftransaction) values ('" + curTranID + "', '" + accountNo + "', '" + date + "', '" + time + "');", conDatabaseInsertToTransaction);
					MySqlDataReader^ myReaderInsertToTransaction;
					
					//Get Current transacition id
					conDatabaseGetCurrentTransactionID->Open();
					myReaderGetCurrentTransactionID = cmDataBaseGetCurrentTransactionID->ExecuteReader();
					if (myReaderGetCurrentTransactionID->Read())
					{
						curTranID = myReaderGetCurrentTransactionID->GetInt32("max(transactionid)") + 1;
					}
					//Create query to insert a new entry into Withdraw table
					MySqlCommand^ cmDataBaseInsertToWithdraw = gcnew MySqlCommand("insert into atm_system.withdraw (transactionID, ammountwithdrawn) values ('" + curTranID + "', '" + withdrawAmount + "');", conDatabaseInsertToWithdraw);
					MySqlDataReader^ myReaderInsertToWithdraw;


					
					//tbDebug->Text += curTranID;
					
					
					//Execute query to insert a new entry into Transaction table
					conDatabaseInsertToTransaction->Open();
					myReaderInsertToTransaction = cmDataBaseInsertToTransaction->ExecuteReader();
					

					//Execute query to insert a new entry into Withdraw table
					conDatabaseInsertToWithdraw->Open();
					myReaderInsertToWithdraw = cmDataBaseInsertToWithdraw->ExecuteReader();

					
					//Display Success Message box with current checking balance
					//MessageBox::Show("You Have Succsesfully Withdrawn $" + withdrawAmount + " into your checkings account. \nCurrent balance is $" + newBalance);
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
			else if (accountType == L"Saving")
			{
				//Create query to get user data from savings and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.saving INNER JOIN atm_system.accounts ON atm_system.saving.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader1;

				try
				{
					

					//Execute query to get saving account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Store the current saving account balance and accountNo into variables
					if (myReader1->Read())
					{
						curBalance = round_up(myReader1->GetDouble("balance"), 2);
						minBalance = round_up(myReader1->GetDouble("minBalance"), 2);
						//tbDebug->Text +=  (curBalance - Double::Parse(withdrawAmount));
						if (minBalance <= curBalance - Double::Parse(withdrawAmount))
						{
							accountNo = myReader1->GetInt32("accountNo").ToString();
							
							//Create query to update savings account balance
							MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance - '" + withdrawAmount + "' where customerID = '" + cID + "' and accountNo = '" + accountNo + "';", conDatabase);
							MySqlDataReader^ myReader;

							//Execute query to update savings account balance
							conDatabase->Open();
							myReader = cmDataBase->ExecuteReader();

							newBalance = round_up(myReader1->GetDouble("balance"), 2).ToString();

						}
						else if (minBalance > curBalance - Double::Parse(withdrawAmount))
						{
							//Display error
							MessageBox::Show("Error: You will be $" + (minBalance - (curBalance - Double::Parse(withdrawAmount))) + " below your minimum balance for account " + accountNo + " which must have a minimum balance of $" + minBalance + ".Please enter a new transfer amount ", "ATM System", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return;
						}
						
					}

					//Create query to insert a new entry into Transaction table
					MySqlCommand^ cmDataBaseInsertToTransaction = gcnew MySqlCommand("insert into atm_system.transaction (transactionid, accountno, dateoftransaction, timeoftransaction) values ('" + curTranID + "', '" + accountNo + "', '" + date + "', '" + time + "');", conDatabaseInsertToTransaction);
					MySqlDataReader^ myReaderInsertToTransaction;

					//Get Current transacition id
					conDatabaseGetCurrentTransactionID->Open();
					myReaderGetCurrentTransactionID = cmDataBaseGetCurrentTransactionID->ExecuteReader();
					if (myReaderGetCurrentTransactionID->Read())
					{
						curTranID = myReaderGetCurrentTransactionID->GetInt32("max(transactionid)") + 1;
					}
					//Create query to insert a new entry into Withdraw table
					MySqlCommand^ cmDataBaseInsertToWithdraw = gcnew MySqlCommand("insert into atm_system.withdraw (transactionID, ammountwithdrawn) values ('" + curTranID + "', '" + withdrawAmount + "');", conDatabaseInsertToWithdraw);
					MySqlDataReader^ myReaderInsertToWithdraw;


					//Execute query to insert a new entry into Transaction table
					conDatabaseInsertToTransaction->Open();
					myReaderInsertToTransaction = cmDataBaseInsertToTransaction->ExecuteReader();

					//Execute query to insert a new entry into Withdraw table
					conDatabaseInsertToWithdraw->Open();
					myReaderInsertToWithdraw = cmDataBaseInsertToWithdraw->ExecuteReader();

					//Display Success Message box with current checking balance
					//MessageBox::Show("You Have Succsesfully Withdrawn $" + withdrawAmount + " into your savings account. \nCurrent balance is $" + newBalance);
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
			conDatabase->Close();
			conDatabase1->Close();
			conDatabaseGetCurrentTransactionID->Close();
			conDatabaseInsertToWithdraw->Close();
			conDatabaseInsertToTransaction->Close();
		}

		void makeTransfer(String^ transferAmount, String^ date, String^ time, String^ transferDirection)
		{
			if (transferDirection == L"SavingToChecking")
			{
				if (checkIfDepositIsValid(transferAmount, date, time, "Checking") == true && checkIfWithdrawIsValid(transferAmount, date, time, "Saving") == true)
				{
					makeWithdraw(transferAmount, date, time, "Saving");
					makeDeposit(transferAmount, date, time, "Checking");
					//Display Success Message box with current savings balance
					MessageBox::Show("You Have Succsesfully Transfered $" + transferAmount + " from your Savings Account and into your Checking Account.");
				}
				else
				{
					return;
				}
			}
			else if (transferDirection == L"CheckingToSaving")
			{
				if (checkIfDepositIsValid(transferAmount, date, time, "Saving") == true && checkIfWithdrawIsValid(transferAmount, date, time, "Checking") == true)
				{
					makeWithdraw(transferAmount, date, time, "Checking");
					makeDeposit(transferAmount, date, time, "Saving");
					
					//Display Success Message box with current savings balance
					MessageBox::Show("You Have Succsesfully Transfered $" + transferAmount + " from your Checking Account and into your Savings Account.");
				}
				else
				{
					return;
				}
			}
			}
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbTransferAmount = (gcnew System::Windows::Forms::Label());
			this->tbTransfer = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnPrev = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->rbtnSavingToChecking = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnCheckingToSaving = (gcnew System::Windows::Forms::RadioButton());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbTransferAmount
			// 
			this->lbTransferAmount->AutoSize = true;
			this->lbTransferAmount->BackColor = System::Drawing::Color::Transparent;
			this->lbTransferAmount->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTransferAmount->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->lbTransferAmount->Location = System::Drawing::Point(12, 21);
			this->lbTransferAmount->Name = L"lbTransferAmount";
			this->lbTransferAmount->Size = System::Drawing::Size(283, 23);
			this->lbTransferAmount->TabIndex = 2;
			this->lbTransferAmount->Text = L"Please Enter A Transfer Amount";
			// 
			// tbTransfer
			// 
			this->tbTransfer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tbTransfer->Location = System::Drawing::Point(16, 74);
			this->tbTransfer->Name = L"tbTransfer";
			this->tbTransfer->Size = System::Drawing::Size(344, 22);
			this->tbTransfer->TabIndex = 3;
			this->tbTransfer->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TransferForm::tbTransfer_KeyPress);
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
			this->tableLayoutPanel1->Location = System::Drawing::Point(16, 200);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(432, 67);
			this->tableLayoutPanel1->TabIndex = 4;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TransferForm::tableLayoutPanel1_Paint);
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
			this->btnClear->Location = System::Drawing::Point(219, 3);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(210, 61);
			this->btnClear->TabIndex = 4;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &TransferForm::btnClear_Click);
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
			this->btnSubmit->Size = System::Drawing::Size(210, 61);
			this->btnSubmit->TabIndex = 3;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = false;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &TransferForm::btnSubmit_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnLogout->BackColor = System::Drawing::Color::MistyRose;
			this->btnLogout->Location = System::Drawing::Point(448, 12);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(108, 32);
			this->btnLogout->TabIndex = 11;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &TransferForm::btnLogout_Click);
			// 
			// btnPrev
			// 
			this->btnPrev->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnPrev->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnPrev->Location = System::Drawing::Point(3, 3);
			this->btnPrev->Name = L"btnPrev";
			this->btnPrev->Size = System::Drawing::Size(88, 31);
			this->btnPrev->TabIndex = 16;
			this->btnPrev->Text = L"Prev";
			this->btnPrev->UseVisualStyleBackColor = false;
			this->btnPrev->Click += gcnew System::EventHandler(this, &TransferForm::btnPrev_Click);
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
			this->tableLayoutPanel2->Location = System::Drawing::Point(13, 287);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(94, 38);
			this->tableLayoutPanel2->TabIndex = 19;
			// 
			// rbtnSavingToChecking
			// 
			this->rbtnSavingToChecking->AutoSize = true;
			this->rbtnSavingToChecking->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rbtnSavingToChecking->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->rbtnSavingToChecking->Location = System::Drawing::Point(16, 121);
			this->rbtnSavingToChecking->Name = L"rbtnSavingToChecking";
			this->rbtnSavingToChecking->Size = System::Drawing::Size(174, 23);
			this->rbtnSavingToChecking->TabIndex = 20;
			this->rbtnSavingToChecking->TabStop = true;
			this->rbtnSavingToChecking->Text = L"Saving To Checking";
			this->rbtnSavingToChecking->UseVisualStyleBackColor = true;
			this->rbtnSavingToChecking->CheckedChanged += gcnew System::EventHandler(this, &TransferForm::radioButton1_CheckedChanged);
			// 
			// rbtnCheckingToSaving
			// 
			this->rbtnCheckingToSaving->AutoSize = true;
			this->rbtnCheckingToSaving->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rbtnCheckingToSaving->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->rbtnCheckingToSaving->Location = System::Drawing::Point(16, 160);
			this->rbtnCheckingToSaving->Name = L"rbtnCheckingToSaving";
			this->rbtnCheckingToSaving->Size = System::Drawing::Size(174, 23);
			this->rbtnCheckingToSaving->TabIndex = 21;
			this->rbtnCheckingToSaving->TabStop = true;
			this->rbtnCheckingToSaving->Text = L"Checking To Saving";
			this->rbtnCheckingToSaving->UseVisualStyleBackColor = true;
			this->rbtnCheckingToSaving->CheckedChanged += gcnew System::EventHandler(this, &TransferForm::radioButton2_CheckedChanged);
			// 
			// TransferForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(214)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->ClientSize = System::Drawing::Size(568, 338);
			this->Controls->Add(this->rbtnCheckingToSaving);
			this->Controls->Add(this->rbtnSavingToChecking);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbTransfer);
			this->Controls->Add(this->lbTransferAmount);
			this->MaximumSize = System::Drawing::Size(586, 385);
			this->MinimumSize = System::Drawing::Size(586, 385);
			this->Name = L"TransferForm";
			this->Text = L"TransferForm";
			this->Load += gcnew System::EventHandler(this, &TransferForm::TransferForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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
private: System::Void TransferForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
//Submits user inputed deposit amount to database and transfers money from the account they are currently in to the other accout and updates both balances
private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
	//Get current date and time and store them in respective variables after properly formating them
	DateTime datetime = DateTime::Now;
	String^ month = datetime.ToString()->Substring(0, 2);
	String^ day = datetime.ToString()->Substring(3, 2);
	String^ year = datetime.ToString()->Substring(5, 4);
	if (year != "2022")
	{
		String^ year = datetime.ToString()->Substring(6, 4);
	}
	String^ date = year + "-" + month + "-" + day + " 00:00:00";
	String^ time = datetime.ToString()->Substring(10, 8);
	if (time->Substring(0, 1) == " ")
	{
		time = "0" + datetime.ToString()->Substring(11, 7);
	}
	
	//String^ transactionID = "22235"; //For testing
	if (transferDir == L"")
	{
		MessageBox::Show("Error: Please select direction of transfer.", "ATM_System", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	//Display a message box asking if user wants to deposit their specified amount (yes/no)
	if (MessageBox::Show("Do you really want to transfer $" + this->tbTransfer->Text + "?", "ATM System", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
	{
		try
		{
			String^ transferAmount = this->tbTransfer->Text;
			makeTransfer(transferAmount, date, time, transferDir);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
		


		//Clear Transfer texbox
		this->tbTransfer->Text = "";
	}
	else
	{
	}
}
//Clears Transfer text box
private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
	this->tbTransfer->Text = "";
}
private: System::Void btnPrev_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	prev->Show();
}
private: System::Void tbTransfer_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == '.') {
		if (this->tbTransfer->Text->Contains(".") && !this->tbTransfer->SelectedText->Contains("."))
			e->Handled = true;
	}

	// Accept only digits ".", and the Backspace character
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	transferDir = "SavingToChecking";
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	transferDir = "CheckingToSaving";
}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}

