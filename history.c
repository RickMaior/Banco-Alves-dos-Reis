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

Transaction new_transaction(char *action, int value){ //TODO function to be done

    Transaction new_transaction;

    strncpy(new_transaction.action, action, 50);
    new_transaction.action[50] = '\0';
    
    new_transaction.value = value;
    get_date(&new_transaction.date);

    return new_transaction;

} 

void print_history(History history){ //TODO function to be done 

    for(int c = 0; c < history.transactions_number ; c++){
        printf("Transaction: ");
        puts(history.transaction[c].action);
        printf("\nAmmount: %d\n", history.transaction[c].value);
        printf("Transaction date: \n\tday: %d\n\tmonth: %d\n\tyear: %d \n", history.transaction[c].date.day, history.transaction[c].date.month, history.transaction[c].date.year);
    }


} 

void update_history(History *history, Transaction new_transaction){ //TODO function to be done

} 


