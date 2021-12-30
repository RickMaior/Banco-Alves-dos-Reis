/*  @name:Account.c
    @description:

    @author: Ricardo Matos & Tiago Rosa
    @version: 1.0
    @date: 00/00/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#include "client.h"

Account new_account(int id ,char account_type, int balance){ // Creates a new client with the parameters as data (where nif was already validated)
    Account account;
    account.id = id;
    account.account_type = account_type; // N - normal, I - Insenta, D - Desativada
    account.balance = balance; // Inicial > 150
    return account;
}

void print_account(Account account){
    //printf("Nome = %s\nNif=%ld", client.nome, client.nif);
}


