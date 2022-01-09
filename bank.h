#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED


#include "client.h"
#include "date.h"

typedef struct{
    int id;
    Client owner[5];
    int total_owners;
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

void find_account_from_id(Bank bank);

void find_account_from_nif(Bank bank); // can be more than one account

void get_name_from_nif(Bank *bank,  Client *client); // see if name is already given to that nif, else it requests the user a name

// BANK functions
Bank get_bank();

void update_file(Bank bank);





#endif