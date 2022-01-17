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

} 

void print_history(History history){ //TODO function to be done 

} 

void update_history(History *history, Transaction new_transaction){ //TODO function to be done

} 


