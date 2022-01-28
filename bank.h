#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED


#include "client.h"
#include "date.h"
#include "history.h"

typedef struct{
    int id;
    Client owner[5];
    int total_owners;
    char account_type; // N -> normal, I -> insent
    int balance; // account ballance in cents
    History history; 
    Date creation_date; // data de criação da conta

    
} Account;

typedef struct{
    Account accounts[100]; 
    int active_accounts; // Ammount of active accounts
    int funds;
} Bank;

// ACCOUNT functions

void new_account(Bank *bank); 

void print_account(Account account , FILE *file);

void find_account_from_id(Bank bank);

void find_account_from_nif(Bank bank); // can be more than one account

void get_name_from_nif(Bank *bank,  Client *client); // see if name is already given to that nif, else it requests the user a name

void deposit_money(Bank *bank);

void withdraw_money(Bank *bank);

void transfer_money(Bank *bank);

void account_to_file(Bank bank);

// BANK functions
Bank get_bank();

void update_file(Bank bank);





#endif