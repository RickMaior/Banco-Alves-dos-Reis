/*  @name:
    @description:

    @author: Ricardo Matos & Tiago Rosa
    @version: 1.0
    @date: 00/00/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "history.h"

/*
    How to update history:
            update_history(&history, new_transaction("Name", value ) );

    where:
        &history -> the variable containing the history that wants to be updated
        Name -> the description of the transaction
        value -> The ammount that was used in the transaction in cents

*/


Transaction new_transaction(char *action, int value){ 

    Transaction new_transaction;

    strncpy(new_transaction.action, action, 50);
    new_transaction.action[50] = '\0';
    
    new_transaction.value = value;

    get_date(&new_transaction.date);

    return new_transaction;

} 

void print_history(History history, FILE *file){ 

    for(int c = 0; c < history.transactions_number ; c++){
        fprintf(file , "Transaction: \n\t");
        fputs(history.transaction[c].action, file);
        if(history.transaction[c].value != 0) fprintf(file , "\tAmmount: %d,%.2d euros\n", history.transaction[c].value/100 , history.transaction[c].value%100); // TODO converter centimos em euros
        fprintf(file , "\tTransaction date: \n\t\tday: %d\n\t\tmonth: %d\n\t\tyear: %d \n", history.transaction[c].date.day, history.transaction[c].date.month, history.transaction[c].date.year);
        fprintf(file ,"\n");
    }

} 

void update_history(History *history, Transaction new_transaction){ 

    for(int i = (*history).transactions_number ; i > 0 ; i--){
        if(i == 3) i = 2;
        (*history).transaction[i] = (*history).transaction[i -1];

    }
    (*history).transaction[0] = new_transaction;

    if( (*history).transactions_number < 3) (*history).transactions_number++;

} 


