#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	time_t	tt = std::chrono::system_clock::to_time_t(now);
	tm local_tm = *localtime(&tt);

	std::cout << std::put_time(&local_tm, "[%Y%m%d_%H%M%S] ");
}

int		Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout
		<< "accounts:"
		<< getNbAccounts()
		<< ";"
		<< "total:"
		<< getTotalAmount()
		<< ";"
		<< "deposits:"
		<< getNbDeposits()
		<< ";"
		<< "withdrawals:"
		<< getNbWithdrawals()
		<< std::endl;
}

Account::Account(int initial_deposit)
{
	this->_totalAmount += this->_amount;
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "amount:"
		<< this->_amount
		<< ";"
		<< "created" 
		<< std::endl;
}

Account::~Account(void)
{
	this->_nbAccounts--;
	this->_totalAmount -= this->_amount;
	this->_totalNbWithdrawals -= this->_nbWithdrawals;
	this->_totalNbDeposits -= this->_nbDeposits;

	this->_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "amount:"
		<< this->_amount
		<< ";"
		<< "closed" 
		<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "p_amount:"
		<< this->_amount
		<< ";"
		<< "deposit:"
		<< deposit
		<< ";";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	std::cout
		<< "amount:"
		<< this->_amount
		<< ";"
		<< "nb_deposits:"
		<< ++this->_nbDeposits
		<< std::endl;
	this->_totalNbDeposits++;
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();

	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "amount:"
		<< this->_amount
		<< ";"
		<< "deposits:" 
		<< this->_nbDeposits
		<< ";"
		<< "withdrawals:" 
		<< this->_nbWithdrawals
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "p_amount:"
		<< this->_amount
		<< ";"
		<< "withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout
			<< "refused"
			<< std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	std::cout
		<< withdrawal
		<< ";"
		<< "amount:"
		<< this->_amount
		<< ";"
		<< "nb_withdrawals:"
		<< ++this->_nbWithdrawals
		<< std::endl;
	this->_totalNbWithdrawals++;
	return (true);
}
