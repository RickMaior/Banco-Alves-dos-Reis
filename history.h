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

Transaction new_transaction(char *action, int value); //TODO function to be done

void print_history(History history); //TODO function to be done 

void update_history(History *history, Transaction new_transaction); //TODO function to be done

#endif