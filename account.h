#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

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

Account new_account(int id ,char account_type, int balance); // TODO create this function

void print_account(Account account);

// TODO : funtion to get last id

#endif