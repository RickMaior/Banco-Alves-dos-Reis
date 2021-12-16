#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

typedef struct{
    int id;
    char owner[51];
    
} Account;

Account new_account(); // TODO do this

void print_account(Account account);



#endif