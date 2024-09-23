#include "Account.hpp"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts( void ) {

    return Account::_nbAccounts;
}

int		Account::getTotalAmount( void ) {

    return _totalAmount;
}

int		Account::getNbDeposits( void ) {

    return _totalNbDeposits;
}

int		Account::getNbWithdrawals( void ) {

    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {

    _displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account()
{}
    
Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {

    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {

    //3 ways to write the same thing
    _amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;

    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

    _displayTimestamp();
    if (withdrawal > _amount) {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int		Account::checkAmount( void ) const {

    return _amount;
}

void	Account::displayStatus( void ) const {

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {

    time_t		timestamp;
    struct tm	*tm_info;
    char		buffer[20];

    time(&timestamp);
    tm_info = localtime(&timestamp);
    strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", tm_info);

    std::cout << buffer;
}

// ************************************************************************** //

