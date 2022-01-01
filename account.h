#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

typedef struct{
    int id;
    char owner[5]; // TODO array de clients
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