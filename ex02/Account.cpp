#include <iostream>
#include <ctime>
#include "./Account.hpp"


int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0){
	++_nbAccounts;
	_totalAmount += initial_deposit;

	return;
}

Account::~Account() {
	return;
}

int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp() {
	time_t timestamp;
	time(&timestamp);
	std::cout << ctime(&timestamp) << std::endl;
}

void Account::displayAccountsInfos() {
	std::cout << std::endl;
	_displayTimestamp();
	std::cout << "Number of accouts: " << _nbAccounts << std::endl;
	std::cout << "Total amount: " << _totalAmount << std::endl;
	std::cout << "Total number of deposits: " << _totalNbDeposits << std::endl;
	std::cout << "Total number of withdrawals: " << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const {
	std::cout << std::endl;
	std::cout << "Index: " << _accountIndex << std::endl;
	std::cout << "Amount: " << _amount << std::endl;
	std::cout << "Number of deposits: " << _nbDeposits << std::endl;
	std::cout << "Number of withdrawals: " << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << deposit << " has been added to account " << _accountIndex << std::endl;
}

int Account::checkAmount() const {
	return _amount;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (checkAmount() < withdrawal) {
		std::cout << "Withdrawal of " << withdrawal << " from account " << _accountIndex << " failed (insufficient funds)" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << withdrawal << " has been withdrawn from accout " << _accountIndex << std::endl;
	return true;
}