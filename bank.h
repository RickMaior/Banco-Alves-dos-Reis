#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include "account.h"


typedef struct{
    Account accounts[100]; 
    int active_accounts; // Ammount of active accounts
    int funds;
} Bank;

Bank get_bank();

void update_file(Bank bank);



#endif