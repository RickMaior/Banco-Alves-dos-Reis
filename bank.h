#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED


#include "client.h"

typedef struct{
    int id;
    Client owner[5];
    char account_type; // N -> normal, I -> insent
    int balance; // account ballance in cents
    char history[3]; // TODO historico da conta
    int creation_date; // data de criação da conta
    // TODO opening date of account
    
} Account;

typedef struct{
    Account accounts[100]; 
    int active_accounts; // Ammount of active accounts
    int funds;
} Bank;

// ACCOUNT functions

void print_account(Account account);

void new_account(Bank *bank); // TODO create this function

// BANK functions
Bank get_bank();

void update_file(Bank bank);





#endif