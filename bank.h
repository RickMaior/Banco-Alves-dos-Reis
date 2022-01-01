#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

typedef struct{
    char accounts[100]; // TODO change to array of accounts
    int active_accounts; // Ammount of active accounts
    int funds;
} Bank;

Bank new_bank();





#endif