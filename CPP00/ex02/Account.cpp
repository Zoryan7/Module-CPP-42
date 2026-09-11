/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 22:59:57 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/10 00:15:38 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
    return ;
}

void Account::makeDeposit(int deposit)
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit <<  ";amount:" << this->_amount+ deposit << ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
    this->_nbDeposits++;
	Account::_totalNbDeposits++;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    return;
}

bool Account::makeWithdrawal(int withdrawal)
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if (withdrawal > this->_amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    std::cout << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
    this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    return (true);
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(0);
    std::tm* local = std::localtime(&t);
      std::cout << '[' << local->tm_year + 1900 << std::setfill('0') << std::setw(2) << local->tm_mon + 1 << std::setw(2) << local->tm_mday << '_' << std::setw(2) << local->tm_hour << std::setw(2) << local->tm_min << std::setw(2) << local->tm_sec << "] ";
}

void Account::displayStatus(void) const
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
    return ;
}

Account::Account( int initial_deposit )
: _accountIndex(_nbAccounts),_amount(initial_deposit), _nbDeposits(0),_nbWithdrawals(0)
{
    this->_totalAmount+= this->_amount;
    this->_nbAccounts++;
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex <<";amount:" << this->_amount << ";created" << std::endl;
    return ;
}

Account::~Account( void )
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex <<";amount:" << this->_amount << ";closed" << std::endl;
    return ;
}
