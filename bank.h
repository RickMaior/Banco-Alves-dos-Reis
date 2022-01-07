#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED


#include "client.h"
#include "date.h"

typedef struct{
    int id;
    Client owner[5];
    char account_type; // N -> normal, I -> insent
    int balance; // account ballance in cents
    char history[3]; // TODO historico da conta
    Date creation_date; // data de criação da conta

    
} Account;

typedef struct{
    Account accounts[100]; 
    int active_accounts; // Ammount of active accounts
    int funds;
} Bank;

// ACCOUNT functions

void new_account(Bank *bank); 

void print_account(Account account);

void check_account(Bank bank);

// BANK functions
Bank get_bank();

void update_file(Bank bank);





#endif