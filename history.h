#ifndef HISTORY_H_INCLUDED
#define HISTORY_H_INCLUDED

#include "date.h"

typedef struct{
    char action[51];
    int value;
    Date date;
} Transaction;

typedef struct{
    Transaction transaction[3];
    int transactions_number; // How many transactions have been done
} History;

Transaction new_transaction(char *action, int value);

void print_history(History history , FILE *file); 

void update_history(History *history, Transaction new_transaction); 

#endif