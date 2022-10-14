/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:29:18 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/06 12:48:43 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::checkAmount(void) const {
	return (Account::_amount);
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit)
	, _nbDeposits(0), _nbWithdrawals(0) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += _amount;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

int Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (_totalAmount);
}

int Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void) {
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	
	std::cout << "[" << t->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << t->tm_mon + 1; 
	std::cout << std::setw(2) << std::setfill('0') << t->tm_mday; 
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << t->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << t->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << t->tm_sec;
	std::cout << "]";
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";";
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;	
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal > _amount || withdrawal < 0)
		std::cout << "withdrawal:refused" << std::endl;
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "amount:" << _amount << ";";
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	return (false);
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}