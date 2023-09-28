DROP DATABASE ATM_SYSTEM;

#Remove Comment "DROP DATABSE" after first run

CREATE DATABASE ATM_SYSTEM;
USE ATM_SYSTEM;
 
CREATE TABLE Customer (
	customerID int NOT NULL AUTO_INCREMENT,
    socialSecurNo int,
    name VARCHAR(50) NOT NULL,
    dateOfBirth VARCHAR(20),
    address VARCHAR(50),
    phoneNum bigint,
    email VARCHAR(100),
    PRIMARY KEY (customerID)
);

CREATE TABLE AtmCard (
	cardNo bigint NOT NULL,
    expirDate datetime,
    pinNo int NOT NULL,
    currBalance float,
    PRIMARY KEY (cardNo)
);

CREATE TABLE Accounts (
	accountNo int NOT NULL AUTO_INCREMENT,
    customerID int NOT NULL,
    dateCreated datetime,
    cardNo bigint NOT NULL,
    routingNumber int,
    balance float,
    minBalance float,
    PRIMARY KEY (accountNo),
    FOREIGN KEY (customerID) REFERENCES Customer(customerID),
    FOREIGN KEY (cardNo) REFERENCES AtmCard(cardNo)
);

CREATE TABLE Saving (
	accountNo int NOT NULL,
    interestRate float,
    minDeposit  float,
    PRIMARY KEY (accountNo),
    FOREIGN KEY (accountNo) REFERENCES Accounts(accountNo)
);

CREATE TABLE Checking (
	accountNo int NOT NULL,
    maxWithdrawAmt float,
    PRIMARY KEY (accountNo),
    FOREIGN KEY (accountNo) REFERENCES Accounts(accountNo)
);


CREATE TABLE Transaction (
	transactionID int NOT NULL AUTO_INCREMENT,
    accountNo int NOT NULL,
    dateOfTransaction datetime,
    timeOfTransaction time,
    PRIMARY KEY (transactionID),
    FOREIGN KEY (accountNo) REFERENCES Accounts(accountNo)
);

CREATE TABLE Withdraw (
	transactionID int NOT NULL,
    ammountWithdrawn float, 
    PRIMARY KEY (transactionID),
    FOREIGN KEY (transactionID) REFERENCES Transaction(transactionID)
);

CREATE TABLE Deposit (
	transactionID int NOT NULL,
    ammountDeposited float, 
    PRIMARY KEY (transactionID),
    FOREIGN KEY (transactionID) REFERENCES Transaction(transactionID)
);

