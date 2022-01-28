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

// Transaction deposito = new_transaction( "Deposito", 2000 );
//printf("deposito %d", deposito.value)
//update_history( &account.history, deposito);

Transaction new_transaction(char *action, int value){ 

    Transaction new_transaction;

    strncpy(new_transaction.action, action, 50);
    new_transaction.action[50] = '\0';
    
    new_transaction.value = value;

    get_date(&new_transaction.date);

    return new_transaction;

} 

void print_history(History history){ 

    for(int c = 0; c < history.transactions_number ; c++){
        printf("Transaction: \n\t");
        puts(history.transaction[c].action);
        printf("\tAmmount: %d\n", history.transaction[c].value); // TODO converter centimos em euros
        printf("\tTransaction date: \n\t\tday: %d\n\t\tmonth: %d\n\t\tyear: %d \n", history.transaction[c].date.day, history.transaction[c].date.month, history.transaction[c].date.year);
        printf("\n");
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


